#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BankAccount.h"
#include <regex.h>
#include <stdbool.h>
#include <ctype.h>

int TestPassword(char *password)
{
  bool hasUpper = false;
  bool hasLower = false;
  bool hasDigit = false;

  for (int i = 0; i < strlen(password); ++i)  //at least one upper character and one lower character one digit 
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

int main(void)
{

  BankAccount *head = NULL;
  BankAccount *tail = NULL;
  head = (BankAccount *)malloc(sizeof(BankAccount));
  tail = (BankAccount *)malloc(sizeof(BankAccount));
  BankAccount *thisNode = NULL;
  thisNode = (BankAccount *)malloc(sizeof(BankAccount));
  char username[12];
  char password[12];
  int userInput;
  int usersCreated = 0;

  while (1)
  {
    int ValidPassword = 0;

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
      (strcmp(GetPassword(username, head), password) == 0) ? BankMenu(thisNode) : printf("passowrd and username do not match\n");
    }
    else
    {
      printf("invalid input");
    }
  }

  PrintNodes(head);

  return 0;
}
