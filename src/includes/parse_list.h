#ifndef PARSE_LIST_H
#define PARSE_LIST_H

#include "symbols.h"

typedef struct node_pl node_pl;
struct node_pl {
    int* val_ptr;
    OPERATOR* oper_ptr;
    node_pl* next;
};

void addToParseList(node_pl** head, int* val_ptr, OPERATOR* oper_ptr);
void printParseList(node_pl* head);

#endif // !PARSE_LIST_H