#ifndef N_ARY_H
#define N_ARY_H

#include "symbols.h"

typedef struct tree_node node_t;
typedef struct list_node node_l;

struct tree_node {
    int* value_ptr;
    OPERATOR* oper_ptr;
    node_l* head;
};

struct list_node {
    node_t* node;
    node_l* next;
};

node_t* initTree(int* value_ptr, OPERATOR* oper);
node_t* addBranch(node_t** root, int* value_ptr, OPERATOR* oper_ptr);
void printTree(node_t* root);

#endif // !N_ARY_H