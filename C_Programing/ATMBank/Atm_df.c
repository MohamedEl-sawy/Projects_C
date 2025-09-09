#include "Atm_df.h"

/**
    @brief Initialize a new Account
    @param No Parameter
    @return No return
*/
void CreateAccount(void) {
    if (NumAccount >= MAX_ACCOUNT) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    Account NewAccount;
    printf("Enter Account Number: ");
    scanf("%d", &NewAccount.Account_Number);
    printf("Enter Account Name: ");
    scanf("%s", NewAccount.Name);
    printf("Enter Password: "); // Prompt for password
    scanf("%s", NewAccount.Password);
    printf("Enter initial Balance: ");
    scanf("%f", &NewAccount.Balance);

    accounts[NumAccount++] = NewAccount;
    printf("Account created successfully.\n");
}

/**
    @brief Deposit in Account
    @param No Parameter
    @return No return
*/
void Deposit(void) {
    int AccNumber;
    float Amount;
    char password[MAX_PASSWORD_LENGTH]; // Password buffer
    printf("Enter Account Number: ");
    scanf("%d", &AccNumber);

    printf("Enter Password: "); // Prompt for password
    scanf("%s", password);

    if (!verifyPassword(AccNumber, password)) {
        printf("Invalid password.\n");
        return;
    }

    int index = findAccount(AccNumber);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter Amount to Deposit: ");
    scanf("%f", &Amount);
    accounts[index].Balance += Amount;
    printf("Deposit successful. New Balance: %.2f\n", accounts[index].Balance);
}

/**
    @brief Withdrawal from Account
    @param No Parameter
    @return No return
*/
void Withdrawal(void) {
    int AccNumber;
    float Amount;
    char password[MAX_PASSWORD_LENGTH]; // Password buffer
    printf("Enter Account Number: ");
    scanf("%d", &AccNumber);

    printf("Enter Password: "); // Prompt for password
    scanf("%s", password);

    if (!verifyPassword(AccNumber, password)) {
        printf("Invalid password.\n");
        return;
    }

    int index = findAccount(AccNumber);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter Amount to Withdraw: ");
    scanf("%f", &Amount);

    if (accounts[index].Balance >= Amount) {
        accounts[index].Balance -= Amount;
        printf("Withdrawal successful. New Balance: %.2f\n", accounts[index].Balance);
    } else {
        printf("Insufficient funds.\n");
    }
}

/**
    @brief Display all Accounts
    @param No Parameter
    @return No return
*/
void DisplayAccount(void) {
    if (NumAccount == 0) {
        printf("No accounts found.\n");
        return;
    }

    printf("List of Accounts:\n");
    printf("Account Number | Name         | Balance\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < NumAccount; i++) {
        printf("%-15d %-12s %.2f\n", accounts[i].Account_Number, accounts[i].Name, accounts[i].Balance);
    }
}

/**
    @brief Find Account by Account Number
    @param AccNumber Account number to search for
    @return Index of account or -1 if not found
*/
int findAccount(int AccNumber) {
    for (int i = 0; i < NumAccount; i++) {
        if (accounts[i].Account_Number == AccNumber) {
            return i;
        }
    }
    return -1;
}

/**
    @brief Verify Password for the account
    @param AccNumber Account number
    @param password Password to verify
    @return 1 if valid, 0 otherwise
*/
int verifyPassword(int AccNumber, const char* password) {
    int index = findAccount(AccNumber);
    if (index != -1) {
        return strcmp(accounts[index].Password, password) == 0; // Compare passwords
    }
    return 0; // Account not found
}

/**
    @brief Transfer funds between accounts
    @param No Parameter
    @return No return
*/
void TransferFunds(void) {
    int fromAccount, toAccount;
    float amount;
    char password[MAX_PASSWORD_LENGTH]; // Password buffer
    printf("Enter Account Number to transfer from: ");
    scanf("%d", &fromAccount);

    printf("Enter Password: "); // Prompt for password
    scanf("%s", password);

    if (!verifyPassword(fromAccount, password)) {
        printf("Invalid password.\n");
        return;
    }

    int fromIndex = findAccount(fromAccount);
    printf("Enter Account Number to transfer to: ");
    scanf("%d", &toAccount);
    int toIndex = findAccount(toAccount);

    if (fromIndex == -1 || toIndex == -1) {
        printf("One or both accounts not found.\n");
        return;
    }

    printf("Enter Amount to Transfer: ");
    scanf("%f", &amount);

    if (accounts[fromIndex].Balance >= amount) {
        accounts[fromIndex].Balance -= amount;
        accounts[toIndex].Balance += amount;
        printf("Transfer Successful. New Balance of %d: %.2f\n", fromAccount, accounts[fromIndex].Balance);
    } else {
        printf("Insufficient funds in account %d.\n", fromAccount);
    }
}

/**
    @brief Update Account Information
    @param No Parameter
    @return No return
*/
void UpdateAccountInfo(void) {
    int accountNumber;
    char password[MAX_PASSWORD_LENGTH]; // Password buffer
    printf("Enter Account Number to update: ");
    scanf("%d", &accountNumber);

    printf("Enter Password: "); // Prompt for password
    scanf("%s", password);

    if (!verifyPassword(accountNumber, password)) {
        printf("Invalid password.\n");
        return;
    }

    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter new name (or press Enter to keep current): ");
    char newName[MAX_NAME_LENGTH];
    scanf(" %[^\n]", newName); // Read string with spaces
    if (strlen(newName) > 0) {
        strcpy(accounts[index].Name, newName); // Update name
    }

    printf("Enter new password (or press Enter to keep current): ");
    char newPassword[MAX_PASSWORD_LENGTH];
    scanf(" %[^\n]", newPassword); // Read string with spaces
    if (strlen(newPassword) > 0) {
        strcpy(accounts[index].Password, newPassword); // Update password
    }

    printf("Account information updated successfully.\n");
}

/**
    @brief Delete an account
    @param No Parameter
    @return No return
*/
void DeleteAccount(void) {
    int accountNumber;
    char password[MAX_PASSWORD_LENGTH]; // Password buffer
    printf("Enter Account Number to delete: ");
    scanf("%d", &accountNumber);

    printf("Enter Password: "); // Prompt for password
    scanf("%s", password);

    if (!verifyPassword(accountNumber, password)) {
        printf("Invalid password.\n");
        return;
    }

    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    for (int i = index; i < NumAccount - 1; i++) {
        accounts[i] = accounts[i + 1];
    }
    NumAccount--;
    printf("Account deleted successfully.\n");
}
