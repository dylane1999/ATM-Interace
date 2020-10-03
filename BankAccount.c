#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BankAccount.h"

void createAccount(BankAccount *AccountCreated, BankAccount *tail, BankAccount *head, char *username, char *password)
{
  BankAccount *temp = head;
  while (temp)
  {
    if (strcmp(temp->username, username) == 0)
    {
      printf("username already in use\n");
      return;
    }
    temp = temp->next;
  }

  strcpy(AccountCreated->username, username);
  strcpy(AccountCreated->password, password);
  AccountCreated->accountBalance = 0;
}

char *GetPassword(char *username, BankAccount *HeadAccount)
{
  BankAccount *temp;
  char *result = (char *)malloc(sizeof(char) * 12);

  temp = HeadAccount;

  while (temp)
  {
    if (strcmp(temp->username, username) != 0)
    {
      temp = temp->next;
    }
    else
    {
      strcpy(result, temp->password);
      return result;
    }
  }
  return result;
}

void PrintNodes(BankAccount *head)
{
  BankAccount *temp = head;
  while (temp)
  {
    printf("\nusername: %s\n", temp->username);
    printf("password: %s\n", temp->password);
    temp = temp->next;
  }
}


void Deposit(BankAccount *thisNode, int amount)
{
  if (amount < 1)
  {
    printf("\ncan not depoist less than one dollar\n");
    return;
  }

  thisNode->accountBalance += amount;
  printf("\nyou deposited: %d\n", amount);
  printf("your account balance: %d\n\n", thisNode->accountBalance);
}

void Withdrawl(BankAccount *thisNode, int amount)
{
  if (thisNode->accountBalance < amount)
  {
    printf("\namount not available\n");
    return;
  }

  thisNode->accountBalance -= amount;
  printf("\nyou Withdrew: %d\n", amount);
  printf("your account balance: %d\n\n", thisNode->accountBalance);
}

void Encrypt(char message[])
{
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

void Transfer(BankAccount *Giver, BankAccount *head, char *RecievingUsername, int amount)
{

  if (Giver->accountBalance < amount | amount < 0)
  {
    printf("\namount not available to transfer or negative input\n");
    return;
  }

  BankAccount *tmp;
  BankAccount *Reciever = NULL;
  tmp = head;
  while (tmp)
  {
    if (strcmp(tmp->username, RecievingUsername) == 0)
    {
      Reciever = tmp;
      break;
    }
    tmp = tmp->next;
  }
  if (Reciever == NULL)
  {
    printf("\naccount does not exist. Transfer Failed\n");
    return;
  }

  Reciever->accountBalance = Reciever->accountBalance + amount;
  Giver->accountBalance = Giver->accountBalance - amount;

  printf("\ngivers accoount: %d\n", Giver->accountBalance);
  printf("reciever accoount: %d\n", Reciever->accountBalance);
  return;
}

int CheckBalance(BankAccount *thisNode)
{
  return thisNode->accountBalance;
}
