#ifndef STACK_H
#define STACK_H

#include "symbols.h"

typedef struct node_s node_s;
struct node_s {
    int* val_ptr;
    OPERATOR* oper_ptr;
    node_s* next;
};

void push(node_s** stack_head, int* val_ptr, OPERATOR* oper_ptr);
node_s* pop(node_s** stack_head);
void destroy(node_s** node);
void printStack(node_s** stack_head);

#endif // !STACK_H