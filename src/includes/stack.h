#ifndef STACK_H
#define STACK_H

#include "list.h"

void push(node_l** stack_base, void* data, TYPE type);
node_l* pop(node_l** stack_base);
void destroyStack(node_l** stack_base);
void printStack(node_l** stack_base);

#endif // !STACK_H