
#ifndef ATM_DF_H
#define ATM_DF_H


#include <stdio.h>
#include <stdlib.h>
#include "Atm_df.c"


#define MAX_ACCOUNT 10
#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 20


typedef struct{
    int Account_Number;
    char Name [MAX_NAME_LENGTH];
    char Password[MAX_PASSWORD_LENGTH]; // Password field
    float Balance;
}Account;

Account accounts[MAX_ACCOUNT];

int NumAccount = 0;


/**
    @brief Initialize the Account
    @param No Parameter
    @return No return
*/

void CreateAccount(void);
/**
    @brief Deposit in Account
    @param No Parameter
    @return No return
*/

void Deposit(void);
/**
    @brief Withdrawal from Account
    @param No Parameter
    @return No return
*/

void Withdrawal(void);
/**
    @brief Show Account Information if Exists
    @param No Parameter
    @return No return
*/

void DisplayAccount(void);
/**
    @brief Change Passwordt by Account Number
    @param AccNumber Account number to search for
    @return Index of account or -1 if not found
*/
void ChangePassword(void); // Function prototype

/**
    @brief Find Account by Account Number
    @param AccNumber Account number to search for
    @return Index of account or -1 if not found
*/

int findAccount(int AccNumber);
/**
    @brief TransferFunds between Acounts
    @param No Parameter
    @return No return
*/

void TransferFunds(void);
/**
    @brief UpdateAccountInfo Information
    @param No Parameter
    @return No return
*/
void UpdateAccountInfo(void);

/**
    @brief DeleteAccount
    @param No Parameter
    @return No return
*/
void DeleteAccount(void);

int verifyPassword(int AccNumber, const char* password); // Function to verify password


#endif // ATM_DF_H
