#include <stdio.h>
#include <stdlib.h>
#include "Atm_df.c"

int main() {
    unsigned int choice;
    do {
        printf("Banking System Menu:\n");
        printf("1. Create Account.\n");
        printf("2. Deposit.\n");
        printf("3. Withdraw.\n");
        printf("4. Display Accounts.\n");
        printf("5. Transfer Funds.\n");
        printf("6. Update Account Info.\n");
        printf("7. Delete Account.\n");
        printf("8. Exit.\n");
        printf("Enter Your Choice: ");
        scanf("%u", &choice);

        switch (choice) {
            case 1:
                CreateAccount();
                break;
            case 2:
                Deposit();
                break;
            case 3:
                Withdrawal();
                break;
            case 4:
                DisplayAccount();
                break;
            case 5:
                TransferFunds();
                break;
            case 6:
                UpdateAccountInfo();
                break;
            case 7:
                DeleteAccount();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);

    return 0;
}
