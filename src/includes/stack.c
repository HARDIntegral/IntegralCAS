#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

#include "symbols.h"

typedef struct node_s node_s;
struct node_s {
    int* val_ptr;
    OPERATOR* oper_ptr;
    node_s* next;
};

node_s* addStackNode(int* val_ptr, OPERATOR* oper_ptr) {
    node_s* node = (node_s*)malloc(sizeof(node_s));
    node->val_ptr = val_ptr;
    node->oper_ptr = oper_ptr;
    node->next = NULL;
    return node;
}

void push(node_s** stack_head, int* val_ptr, OPERATOR* oper_ptr) {
    node_s* new_node = addStackNode(val_ptr, oper_ptr);
    new_node->next = *stack_head;
    *stack_head = new_node;
}

node_s* pop(node_s** stack_head) {
    node_s* tmp = *stack_head;
    *stack_head = (*stack_head)->next;
    return tmp;
}

void destroy(node_s** node) {
    free(*node);
    *node = NULL;
}

void printStack(node_s** stack_head) {
    node_s* tmp = *stack_head;
    while (tmp != NULL) {
        if (tmp->val_ptr != NULL)
            printf("Value - %d\n", *(tmp->val_ptr));
        else if (tmp->oper_ptr != NULL)
            printf("Operator - %d\n", *(tmp->oper_ptr));
        tmp = tmp->next;
    }
}