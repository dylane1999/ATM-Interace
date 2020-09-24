#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BankAccount.h"

void createAccount(BankAccount *AccountCreated, BankAccount *tail,  char *username, char *password){

  strcpy(AccountCreated-> username, username);
  strcpy(AccountCreated-> password, password);
  tail-> next = AccountCreated;
  AccountCreated-> next = NULL;
  tail = AccountCreated;

}

char* GetPassword(char *username, BankAccount *HeadAccount){
  BankAccount *temp;
  temp = (BankAccount *)malloc(sizeof(BankAccount));

  temp = HeadAccount;

  while (temp)
  {
    if (!strcmp(temp-> username, username) == 0)
    {
      temp = temp -> next;
    }
    else
    {
      return temp ->password;
    }
    
  }

  printf("Account does not exist.\n");
  return NULL;

  
}



