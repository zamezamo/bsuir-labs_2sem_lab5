/* 
*  16/03/21
*  Artyom Zamoyskiy
*
*  "stack.h for string" library
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char dat[20];

typedef struct Stack
{
    char data[20];
    struct Stack *next;
} Stack;

void push(Stack **head, char *data)
{
    Stack *tmp = (Stack *)malloc(sizeof(Stack));
    strcpy(tmp->data, data);
    tmp->next = (*head);
    (*head) = tmp;
}


char* pop (Stack **head) {
    Stack* prev = NULL;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    strcpy(dat, prev->data);
    (*head) = (*head)->next;
    free(prev);
    return dat;
}


