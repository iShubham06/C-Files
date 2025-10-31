#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account 
{
    int account_number;
    char name[50];
    float balance;
};

//Function prototypes
void create_account(struct Account *acc);
void deposit(struct Account *acc);
void withdraw(struct Account *acc);
void cheack_balance(struct Account *acc);

int main() 
{
    struct Account acc;
    int choice;
    int created = 0;

    while (1) 
    {
        printf("\nBanking System Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                create_account(&acc);
                created = 1;
                break;
            case 2:
                if (created) 
                    deposit(&acc);
                else
                    printf("Please create an account first!\n");
                break;
            case 3:
                if (created) 
                    withdraw(&acc);
                else
                    printf("Please create an account first!\n");
                break;
            case 4:
                if (created)
                    cheack_balance(&acc);
                else
                    printf("Please create an account first!\n");
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new account
void create_account(struct Account *acc) 
{
    printf("Enter account number: ");
    scanf("%d", &acc->account_number);
    printf("Enter account holder name: ");
    scanf("%s", acc->name);
    acc->balance = 0.0;
    printf("Account created successfully!\n");
}

// Function to deposit money into the account
void deposit(struct Account *acc) 
{
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) 
    {
        acc->balance += amount;
        printf("Deposited: %.2f\n", amount);
    } 
    else 
    {
        printf("Invalid amount! Please enter a positive value.\n");
    }
}


// Function to withdraw money from the account
void withdraw(struct Account *acc) 
{
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= acc->balance) 
    {
        acc->balance -= amount;
        printf("Withdrawn: %.2f\n", amount);
    } 
    else if (amount > acc->balance) 
    {
        printf("Insufficient balance!\n");
    } 
    else 
    {
        printf("Invalid amount! Please enter a positive value.\n");
    }
}


// Function to check the account balance
void cheack_balance(struct Account *acc) 
{
    printf("Account Number: %d\n", acc->account_number);
    printf("Account Holder: %s\n", acc->name);
    printf("Current Balance: %.2f\n", acc->balance);
}
