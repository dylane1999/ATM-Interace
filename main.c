#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BankAccount.h"

int main(void)
{

  BankAccount *head = NULL;
  BankAccount *tail = NULL;
  head = (BankAccount *)malloc(sizeof(BankAccount));
  tail = (BankAccount *)malloc(sizeof(BankAccount));
  char username[12];
  char password[12];
  int userInput;
  int usersCreated = 0;

  while (1)
  {

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

    if (userInput == 1 && usersCreated < 1)
    {
      BankAccount *thisNode = NULL;
      thisNode = (BankAccount *)malloc(sizeof(BankAccount));
      createAccount(thisNode, tail, head, username, password);
      usersCreated++;
      head = thisNode;
      tail = thisNode;
    }
    else if (userInput == 1)
    {
      BankAccount *thisNode = NULL;
      thisNode = (BankAccount *)malloc(sizeof(BankAccount));
      createAccount(thisNode, tail, head, username, password);
      usersCreated++;
      tail->next = thisNode;
      thisNode->next = NULL;
      tail = thisNode;
    }
    else if (userInput == 2 && usersCreated > 0)
    {
      (strcmp(GetPassword(username, head), password) == 0) ? printf("passowrd and username match\n") : printf("passowrd and username do not match\n");
    }
    else
    {
      printf("invalid input");
    }
  }

  PrintNodes(head);

  return 0;
}
