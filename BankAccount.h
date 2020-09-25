#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

typedef struct BankAccount_struct
{
  char username[12];
  char password[12]; 
  int accountBalance;
  struct BankAccount_struct* next;

} BankAccount;

//void transferFunds(BankAccount *AccountSending, BankAccount *AccountRecieving, int amount );
void Deposit(BankAccount *Account, int amount);
void Withdrawl(BankAccount *Account, int amount);
char* GetPassword(char *username, BankAccount *HeadAccount);
void createAccount(BankAccount *AccountCreated, BankAccount *tail, BankAccount *head, char *username, char *password);
void PrintNodes(BankAccount *head);







#endif // BANKACCOUNT_H