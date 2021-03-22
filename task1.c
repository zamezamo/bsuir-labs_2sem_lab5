/* 
* 16/03/21
* Artyom Zamoyskiy
*
* Task:
*  RU: 1. Создать стек для символов. Максимальный размер стека вводится с экрана. 
*  Создать функции для ввода и вывода элементов стека. Добавлять символы с экрана в стек. 
*  В случае совпадения вводимого символа с вершиной стека вытолкнуть его и распечатать ее.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main()
{
  int n = 0, temp;
  printf("How many numbers(words) in text files? - ");
  while (1)
  {
    temp = scanf("%d", &n);
    if (temp != 1)
      printf("Enter only number - ");
    else
      break;
  }

  fflush(stdin);
  printf("\n");

  FILE *structnum = fopen("structnum.txt", "w+");
  FILE *structword = fopen("structword.txt", "w+");

  char tempnum[20];
  char tempword[20];

  for (int i = 0; i < n; i++)
  {
    printf("Enter %dth number - ", i + 1);
    temp = scanf("%s", tempnum);
    fflush(stdin);
    printf("Enter %dth word - ", i + 1);
    scanf("%20s", tempword);
    fprintf(structnum, "%s ", tempnum);
    fprintf(structword, "%s ", tempword);
  }

  rewind(structnum);
  rewind(structword);

  Stack *head = NULL;

  for (int i = 0; i < n; i++)
  {
    fscanf(structnum, "%s", tempnum);
    push(&head, tempnum);
    fscanf(structword, "%s", tempword);
    push(&head, tempword);
  }

  FILE *newfile = fopen("newfile.txt", "w+");

  for (int i = 0; i < 2 * n; i++)
  {
    fprintf(newfile, "%s ", pop(&head));
  }

  fclose(structnum);
  fclose(structword);
  fclose(newfile);
}
