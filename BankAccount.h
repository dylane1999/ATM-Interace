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
void BankMenu(BankAccount *thisNode);
void Transfer(BankAccount *Giver, BankAccount *head, char *RecievingUsername,  int amount);
void Encrypt(char message[]);








#endif // BANKACCOUNT_H