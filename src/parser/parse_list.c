#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "../includes/symbols.h"

typedef struct node_pl node_pl;
struct node_pl
{
    int *val_ptr;
    OPERATOR *oper_ptr;
    node_pl *next;
};

node_pl* createParseListNode(int* val_ptr, OPERATOR* oper_ptr)
{
    node_pl* new = (node_pl*)malloc(sizeof(node_pl));
    new->val_ptr = val_ptr;
    new->oper_ptr = oper_ptr;
    new->next = NULL;
    return new;
}

void addToParseList(node_pl** head, int* val_ptr, OPERATOR* oper_ptr)
{
    node_pl* tmp = *head;
    node_pl* new = createParseListNode(val_ptr, oper_ptr);
    if (tmp == NULL)
        *head = new;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
}

void printParseList(node_pl* head)
{
    node_pl* tmp = head;
    while (tmp != NULL){
        if (tmp->val_ptr != NULL)
            printf("Value - %d\n", *(tmp->val_ptr));
        else if (tmp->oper_ptr != NULL)
            printf("Operation - %d\n", *(tmp->oper_ptr));
        tmp = tmp->next;
    }
    printf("\n");
}

void destroyParseList(node_pl** head){
    node_pl* tmp = *head;
    while (*head != NULL) {
        if (*head != NULL) {
            free(*head);
            *head = tmp->next;
        }
        *head = NULL;
    }
}
