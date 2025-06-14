#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <fstream>

class Book {
private:
    std::string Name;
    std::string ID;
    bool isborrowed = false;

public:
    Book() {}
    Book(std::string name, std::string id) : Name(name), ID(id) {}

    std::string getName() {
        return Name;
    }

    void setName(std::string name) {
        this->Name = name;
    }

    std::string getID() {
        return ID;
    }

    void setID(std::string id) {
        this->ID = id;
    }

    bool getIsBorrowed() {
        return isborrowed;
    }

    void setIsBorrowed(bool status) {
        isborrowed = status;
    }
};

class User {
private:
    std::string Account;
    std::string Password;
    int Max_borrow = 20;
    int Num_borrow = 0;

public:
    void setAccount(std::string account) {
        this->Account = account;
    }

    std::string getAccount() {
        return Account;
    }

    void setPassword(std::string password) {
        this->Password = password;
    }

    std::string getPassword() {
        return Password;
    }

    int getMaxBorrow() {
        return Max_borrow;
    }

    int getNumBorrow() {
        return Num_borrow;
    }

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

    User() {}
    User(std::string account, std::string password) : Account(account), Password(password) {}
};

std::vector<User> users;
const std::string USER_FILE = "users.dat";

void loadUsers() {
    std::ifstream file(USER_FILE);
    if (!file) return;
    
    std::string account, password;
    while (file >> account >> password) {
        users.push_back(User(account, password));
    }
    file.close();
}

void saveUsers() {
    std::ofstream file(USER_FILE);
    if (!file) {
        std::cout << "Failed to save user data!" << std::endl;
        return;
    }
    
    for (const auto& user : users) {
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
    for (const auto& user : users) {
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
    
    for (const auto& user : users) {
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
    
    users.push_back(User(account, password));
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
        
        if (choice == 1) {
            login();
        } else if (choice == 2) {
            registerUser();
        } else if (choice == 0) {
            std::cout << "Thank you for using the system. Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice, please try again!" << std::endl;
        }
    }
    
    return 0;
}