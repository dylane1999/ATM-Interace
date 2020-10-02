#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BankAccount.h"

void createAccount(BankAccount *AccountCreated, BankAccount *tail, BankAccount *head, char *username, char *password)
{
  while (head)
  {
    if (strcmp(head->username, username) == 0)
    {
      printf("username already in use\n");
      return;
    }
    head = head->next;
  }

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

void PrintNodes(BankAccount *head)
{
  while (head)
  {
    printf("%s\n", head->username);
    head = head->next;
  }
}

void BankMenu(BankAccount *thisNode)
{
  int userInput;
  int amount;
  printf("\ndeposit: 1\n");
  printf("\nwithdrawl: 2\n");
  scanf("%d", &userInput);
  printf("enter amount: ");
  scanf("%d", &amount);
  if (userInput == 1)
  {

    Deposit(thisNode, amount);
  }
  else if (userInput == 2)
  {
    Withdrawl(thisNode, amount);
  }
  else
  {
    printf("\n invalid entry");
  }
}

void Deposit(BankAccount *thisNode, int amount)
{
  if (amount < 1)
  {
    printf("can not depoist less than one dollar");
    return;
  }

  thisNode->accountBalance += amount;
  printf("\nyou deposited: %d\n", amount);
  printf("your account balance: %d\n", thisNode->accountBalance);
}

void Withdrawl(BankAccount *thisNode, int amount)
{
  if (thisNode->accountBalance < amount)
  {
    printf("amount not available");
    return;
  }

  thisNode->accountBalance -= amount;
  printf("\nyou Withdrew: %d\n", amount);
  printf("your account balance: %d\n\n", thisNode->accountBalance);
}

void Encrypt(char message[]){
  int i, key;
  key = 3;
  char *pointer = message;
  char *temp;
  for (i = 0; i < strlen(message); ++i)
  {
    temp = pointer + i;
    if (*temp >= 'a' && *temp <= 'z')
    {
      *temp = *temp + key;
      if (*temp > 'z')
      {
        *temp = *temp - 'z' + 'a' - 1;
      }
    }
    else if (*temp >= 'A' && *temp <= 'Z')
    {
      *temp = *temp + key;
      if (*temp > 'Z')
      {
        *temp = *temp - 'Z' + 'A' - 1;
      }
    }
  }
}

void Transfer(BankAccount *Giver, BankAccount *Reciever,  int amount){

    if (Giver->accountBalance < amount | amount < 0)
  {
    printf("amount not available to transfer");
    return;
  }

  Giver->accountBalance = Giver->accountBalance - amount;
  Reciever->accountBalance = Reciever->accountBalance + amount;

}
