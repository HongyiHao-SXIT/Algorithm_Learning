#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Book {
private:
  std::string Name;
  std::string ID;
  bool isborrowed = false;

public:
  Book() = default;
  Book(std::string name, std::string id) : Name(name), ID(id) {}

  std::string getName() const { return Name; }
  void setName(const std::string &name) { Name = name; }

  std::string getID() const { return ID; }
  void setID(const std::string &id) { ID = id; }

  bool getIsBorrowed() const { return isborrowed; }
  void setIsBorrowed(bool status) { isborrowed = status; }
};

class User {
private:
  std::string Account;
  std::string Password;
  int Max_borrow = 20;
  int Num_borrow = 0;

public:
  User() = default;
  User(const std::string &account, const std::string &password)
      : Account(account), Password(password) {}

  void setAccount(const std::string &account) { Account = account; }
  std::string getAccount() const { return Account; }

  void setPassword(const std::string &password) { Password = password; }
  std::string getPassword() const { return Password; }

  int getMaxBorrow() const { return Max_borrow; }
  int getNumBorrow() const { return Num_borrow; }

  bool borrowBook() {
    if (Num_borrow < Max_borrow) {
      Num_borrow++;
      return true;
    }
    return false;
  }

  bool returnBook() {
    if (Num_borrow > 0) {
      Num_borrow--;
      return true;
    }
    return false;
  }
};

std::vector<User> users;
const std::string USER_FILE = "users.dat";

void loadUsers() {
  std::ifstream file(USER_FILE);
  if (!file.is_open())
    return;

  std::string account, password;
  while (file >> account >> password) {
    users.emplace_back(account, password);
  }

  file.close();
}

void saveUsers() {
  std::ofstream file(USER_FILE);
  if (!file.is_open()) {
    std::cout << "Failed to save user data!" << std::endl;
    return;
  }

  for (const auto &user : users) {
    file << user.getAccount() << " " << user.getPassword() << std::endl;
  }

  file.close();
}

void login() {
  std::string account, password;
  std::cout << "Account: ";
  std::cin >> account;
  std::cout << "Password: ";
  std::cin >> password;

  bool success = false;
  for (const auto &user : users) {
    if (user.getAccount() == account && user.getPassword() == password) {
      success = true;
      std::cout << "Login successful! Welcome " << account << std::endl;
      break;
    }
  }

  if (!success) {
    std::cout << "Invalid account or password!" << std::endl;
  }
}

void registerUser() {
  std::string account, password, confirmPassword;

  std::cout << "Please enter a new account: ";
  std::cin >> account;

  for (const auto &user : users) {
    if (user.getAccount() == account) {
      std::cout << "This account already exists!" << std::endl;
      return;
    }
  }

  do {
    std::cout << "Please enter a password (at least 6 characters): ";
    std::cin >> password;
    if (password.length() < 6) {
      std::cout << "Password must be at least 6 characters long!" << std::endl;
    }
  } while (password.length() < 6);

  do {
    std::cout << "Please confirm the password: ";
    std::cin >> confirmPassword;
    if (confirmPassword != password) {
      std::cout << "The passwords do not match! Please re-enter." << std::endl;
    }
  } while (confirmPassword != password);

  users.emplace_back(account, password);
  saveUsers();
  std::cout << "Registration successful! You can now log in." << std::endl;
}

int main() {
  loadUsers();

  int choice;
  while (true) {
    std::cout << "\n===== Library Management System =====" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Register" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Please choose: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      login();
      break;
    case 2:
      registerUser();
      break;
    case 0:
      std::cout << "Thank you for using the system. Goodbye!" << std::endl;
      return 0;
    default:
      std::cout << "Invalid choice, please try again!" << std::endl;
    }
  }
}
