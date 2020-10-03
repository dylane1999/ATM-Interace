#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BankAccount.h"
#include <stdbool.h>
#include <ctype.h>

int TestPassword(char *password)
{
  bool hasUpper = false;
  bool hasLower = false;
  bool hasDigit = false;

  for (int i = 0; i < strlen(password); ++i) //at least one upper character and one lower character one digit
  {

    if (islower(password[i]))
      hasLower = true;

    if (isupper(password[i]))
      hasUpper = true;

    if (isdigit(password[i]))
      hasDigit = true;
  }

  return ((hasLower && hasUpper && hasDigit) ? 1 : 0);
}

void BankMenu(BankAccount *thisNode, BankAccount *head)
{
  printf("\naccount balance: %d\n", CheckBalance(thisNode));
  int userInput;
  int amount;
  char RecievingUsername[12];
  printf("\ndeposit: 1\n");
  printf("\nwithdrawl: 2\n");
  printf("\nTransfer: 3\n");
  scanf("%d", &userInput);
  printf("enter amount: ");
  scanf("%d", &amount);
  if (userInput == 1)
  {

    Deposit(thisNode, amount);
    printf("\naccount balance: %d\n", CheckBalance(thisNode));
    return;
  }
  else if (userInput == 2)
  {
    Withdrawl(thisNode, amount);
    return;
  }
  else if (userInput == 3)
  {
    printf("\nenter username of transfer recipient: \n");
    scanf("%s", RecievingUsername);
    Transfer(thisNode, head, RecievingUsername, amount);
  }

  else
  {
    printf("\n invalid entry");
  }
}

int main(void)
{

  BankAccount *head = NULL;
  BankAccount *tail = NULL;
  head = (BankAccount *)malloc(sizeof(BankAccount));
  tail = (BankAccount *)malloc(sizeof(BankAccount));
  BankAccount *thisNode = NULL;
  char username[12];
  char password[12];
  int userInput;
  int usersCreated = 0;
  int InUse = 1;

  while (InUse)
  {
  
    int ValidPassword = 0;
    thisNode = (BankAccount *)malloc(sizeof(BankAccount));


    printf("sign up : 1\n");
    printf("log in : 2\n");
    printf("quit: 3\n ");
    scanf("%d", &userInput);

    if (userInput == 3)
    {
      printf("quit");
      return 0;
    }
    printf("input username: ");
    scanf("%s", username);
    printf("\ninput password: ");
    scanf("%s", password);
    if ((strlen(password) > 12) | (strlen(username) > 12))
    {
      printf("username and password must be under 12 characters in length");
      return 0;
    }
    ValidPassword = TestPassword(password);
    if (!ValidPassword)
    {
      printf("not a valid password, must contain at least one upper character and one lower character one digit. \n");
      return 0;
    }



    Encrypt(password);

    if (userInput == 1 && usersCreated < 1)
    {
      createAccount(thisNode, tail, head, username, password);
      usersCreated++;
      head = thisNode;
      tail = thisNode;
    }
    else if (userInput == 1)
    {
      createAccount(thisNode, tail, head, username, password);
      usersCreated++;
      tail->next = thisNode;
      thisNode->next = NULL;
      tail = thisNode;
    }
    else if (userInput == 2 && usersCreated > 0)
    {
      BankAccount *tmp = head;
      BankAccount *result = NULL;
      while (tmp)
      {
        if (strcmp(tmp->username, username) == 0)
        {
          result = tmp;
          break;
        }
        tmp = tmp->next;
      }
      
      (strcmp(GetPassword(username, head), password) == 0) ? BankMenu(result, head) : printf("password and username do not match\n");

    }
    else
    {
      printf("invalid input");
    }
  }

  return 0;
}
