#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

#include "list.h"

void push(node_l** stack_base, void* data, TYPE type) {
    pushNode(stack_base, data, type);
}

node_l* pop(node_l* stack_base) {
    node_l* tmp = stack_base;
    stack_base = getNextNode(stack_base);
    return tmp;
}

void destroyStack(node_l** stack_base) {
    destroyList(stack_base);
}

void printStack(node_l** stack_base) {
    printList(stack_base);
}