#include <stdio.h>
#include <math.h>
#include <string.h>

struct User {
    char ID[50];
    char Name[50];
    char Address[100];
    char Phone_Num[20];
    int Age;
    char Account[50];
    char Password[50];
    double Balance;
}user;

void login(struct User user) {
    char inputAccount[50];
    char inputPassword[50];
    char fileAccount[50];
    char filePassword[50];

    printf("Enter account: ");
    scanf("%49s", inputAccount);

    printf("Enter password: ");
    scanf("%49s", inputPassword);

    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("⚠ No users registered yet. Please register first.\n");
        return;
    }

    int success = 0;
    while (fscanf(fp, "%49[^,],%49s\n", fileAccount, filePassword) == 2) {
        if (strcmp(inputAccount, fileAccount) == 0 &&
            strcmp(inputPassword, filePassword) == 0) {
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
}

void registerUser() {
    struct User user;
    printf("\n--- Register ---\n");
    printf("Enter account: ");
    scanf("%49s", user.Account);
    printf("Enter password: ");
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

    printf("Your current balance: %.2f\n", user->Balance);
    printf("How much money do you want to save? ");

    if (fgets(buf, sizeof(buf), stdin) != NULL) {
        cash = strtod(buf, NULL);

        if (cash < 0) {
            printf("Invalid amount!\n");
            return;
        }

        user->Balance += cash;
        printf("Deposit successful! New balance: %.2f\n", user->Balance);
    } else {
        printf("Input error!\n");
    }
}

void get_money(struct User *user) {
    char buf[50];
    double cash;

    printf("Your current balance: %.2f\n", user->Balance);
    printf("How much money do you want to withdraw? ");

    if (fgets(buf, sizeof(buf), stdin) != NULL) {
        cash = strtod(buf, NULL);

        if (cash < 0) {
            printf("Invalid amount!\n");
            return;
        }

        if (cash > user->Balance) {
            printf("Insufficient balance!\n");
            return;
        }

        user->Balance -= cash;
        printf("Withdrawal successful! New balance: %.2f\n", user->Balance);
    } else {
        printf("Input error!\n");
    }
}

void transfer(struct User *fromUser, struct User *toUser){
    char buf[50];
    double amount;
    printf("Your current balance: %.2f\n", fromUser->Balance);
    printf("Enter amount to transfer: ");

        if (fgets(buf, sizeof(buf), stdin) != NULL) {
        amount = strtod(buf, NULL);

        if (amount <= 0) {
            printf("Invalid amount!\n");
            return;
        }

        if (amount > fromUser->Balance) {
            printf("Insufficient balance!\n");
            return;
        }

        fromUser->Balance -= amount;
        toUser->Balance += amount;

        printf("Transfer successful!\n");
        printf("Your new balance: %.2f\n", fromUser->Balance);
    } else {
        printf("Input error!\n");
    }
}
int main() {

    return 0;
}
