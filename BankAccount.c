#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BankAccount.h"

void createAccount(BankAccount *AccountCreated, BankAccount *tail, BankAccount *head, char *username, char *password)
{


    strcpy(AccountCreated->username, username);
    strcpy(AccountCreated->password, password);
    AccountCreated->accountBalance = 0;

  
}

char *GetPassword(char *username, BankAccount *HeadAccount)
{

  BankAccount *temp;
  temp = (BankAccount *)malloc(sizeof(BankAccount));

  temp = HeadAccount;

  while (temp)
  {
    if (strcmp(temp->username, username) != 0)
    {
      temp = temp->next;
    }
    else
    {
      return temp->password;
    }
  }
  return NULL;
}





void PrintNodes(BankAccount *head){
   while (head)
  {
    printf("%s\n", head -> username);
    head = head-> next;

  }
}

void Deposit()
