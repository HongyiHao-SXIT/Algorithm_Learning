#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
  char ID[50];
  char Name[50];
  char Address[100];
  char Phone_Num[20];
  int Age;
  char Account[50];
  char Password[50];
  double balance;
};

void registerUser() {
  struct User user;
  printf("\n--- Register ---\n");
  printf("Enter account: \n");
  scanf("%49s", user.Account);
  printf("Enter password: \n");
  scanf("%49s", user.Password);

  FILE *fp = fopen("users.txt", "a");
  if (fp == NULL) {
    printf("Error opening file!\n");
    return;
  }
  fprintf(fp, "%s,%s\n", user.Account, user.Password);
  fclose(fp);

  printf("✅ Registration successful!\n");
}

int login(struct User *user) {
  char inputAccount[50];
  char inputPassword[50];
  char fileAccount[50];
  char filePassword[50];

  printf("Enter account: \n");
  scanf("%49s", inputAccount);
  printf("Enter password: \n");
  scanf("%49s", inputPassword);

  FILE *fp = fopen("users.txt", "r");
  if (fp == NULL) {
    printf("⚠ No users registered yet. Please register first.\n");
    return 0;
  }

  int success = 0;
  while (fscanf(fp, "%49[^,],%49s\n", fileAccount, filePassword) == 2) {
    if (strcmp(inputAccount, fileAccount) == 0 &&
        strcmp(inputPassword, filePassword) == 0) {
      strcpy(user->Account, inputAccount);
      strcpy(user->Password, inputPassword);
      success = 1;
      break;
    }
  }
  fclose(fp);

  if (success) {
    printf("✅ Login successful!\n");
  } else {
    printf("❌ Login failed. Wrong account or password.\n");
  }
  return success;
}

void modify_information(struct User *user) {
  int choice;
  printf("\n--- Modify User Information ---\n");
  printf("1. Change Name\n");
  printf("2. Change Address\n");
  printf("3. Change Phone Number\n");
  printf("4. Change Age\n");
  printf("5. Change Password\n");
  printf("6. Exit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  getchar();

  switch (choice) {
    case 1:
      printf("Enter new name: ");
      fgets(user->Name, sizeof(user->Name), stdin);
      user->Name[strcspn(user->Name, "\n")] = '\0';
      break;
    case 2:
      printf("Enter new address: ");
      fgets(user->Address, sizeof(user->Address), stdin);
      user->Address[strcspn(user->Address, "\n")] = '\0';
      break;
    case 3:
      printf("Enter new phone number: ");
      fgets(user->Phone_Num, sizeof(user->Phone_Num), stdin);
      user->Phone_Num[strcspn(user->Phone_Num, "\n")] = '\0';
      break;
    case 4:
      printf("Enter new age: ");
      scanf("%d", &user->Age);
      break;
    case 5:
      printf("Enter new password: ");
      fgets(user->Password, sizeof(user->Password), stdin);
      user->Password[strcspn(user->Password, "\n")] = '\0';
      break;
    case 6:
      printf("Exit modify menu.\n");
      return;
    default:
      printf("Invalid choice.\n");
  }
}

void save_money(struct User *user) {
  char buf[50];
  double cash;

  printf("Your current balance: %.2f\n", user->balance);
  printf("How much money do you want to save? ");

  if (fgets(buf, sizeof(buf), stdin) != NULL) {
    cash = strtod(buf, NULL);
    if (cash < 0) {
      printf("Invalid amount!\n");
      return;
    }
    user->balance += cash;
    printf("Deposit successful! New balance: %.2f\n", user->balance);
  } else {
    printf("Input error!\n");
  }
}

void get_money(struct User *user) {
  char buf[50];
  double cash;

  printf("Your current balance: %.2f\n", user->balance);
  printf("How much money do you want to withdraw? ");

  if (fgets(buf, sizeof(buf), stdin) != NULL) {
    cash = strtod(buf, NULL);
    if (cash < 0) {
      printf("Invalid amount!\n");
      return;
    }
    if (cash > user->balance) {
      printf("Insufficient balance!\n");
      return;
    }
    user->balance -= cash;
    printf("Withdrawal successful! New balance: %.2f\n", user->balance);
  } else {
    printf("Input error!\n");
  }
}

void transfer(struct User *fromUser, struct User *toUser) {
  char buf[50];
  double amount;

  printf("Your current balance: %.2f\n", fromUser->balance);
  printf("Enter amount to transfer: ");

  if (fgets(buf, sizeof(buf), stdin) != NULL) {
    amount = strtod(buf, NULL);
    if (amount <= 0) {
      printf("Invalid amount!\n");
      return;
    }
    if (amount > fromUser->balance) {
      printf("Insufficient balance!\n");
      return;
    }
    fromUser->balance -= amount;
    toUser->balance += amount;

    printf("Transfer successful!\n");
    printf("Your new balance: %.2f\n", fromUser->balance);
  } else {
    printf("Input error!\n");
  }
}

void menu() {
  struct User currentUser = {0};
  struct User anotherUser = {0};
  int loggedIn = 0;
  int choice;

  while (1) {
    printf("\n========== HongMing Bank System ==========\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Modify User Information\n");
    printf("4. Deposit Money\n");
    printf("5. Withdraw Money\n");
    printf("6. Transfer Money\n");
    printf("7. Show Current Balance\n");
    printf("0. Exit\n");
    printf("------------------------------------------\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
      printf("Invalid input.\n");
      while (getchar() != '\n');
      continue;
    }
    getchar();

    switch (choice) {
      case 1:
        registerUser();
        break;

      case 2:
        loggedIn = login(&currentUser);
        break;

      case 3:
        if (loggedIn)
          modify_information(&currentUser);
        else
          printf("⚠ Please login first.\n");
        break;

      case 4:
        if (loggedIn)
          save_money(&currentUser);
        else
          printf("⚠ Please login first.\n");
        break;

      case 5:
        if (loggedIn)
          get_money(&currentUser);
        else
          printf("⚠ Please login first.\n");
        break;

      case 6:
        if (loggedIn) {
          printf("Enter target account name for demo transfer: ");
          scanf("%49s", anotherUser.Account);
          getchar();
          transfer(&currentUser, &anotherUser);
        } else {
          printf("⚠ Please login first.\n");
        }
        break;

      case 7:
        if (loggedIn)
          printf("Current balance: %.2f\n", currentUser.balance);
        else
          printf("⚠ Please login first.\n");
        break;

      case 0:
        printf("Thank you for using HongMing Bank System!\n");
        return;

      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
}

int main() {
  menu();
  return 0;
}
