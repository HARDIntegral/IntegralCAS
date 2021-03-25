#ifndef N_ARY_H
#define N_ARY_H

#include "symbols.h"

typedef struct TreeNode node_t;
struct TreeNode {
    int value;
    OPERATOR symbol;
    node_t** children;
    int total_children;
    int availableBranches;
};

node_t* initTree(int value, OPERATOR symbol, const int numChildren);
void addBranch(node_t** root, int value, OPERATOR symbol, const int numInputs);
void printTree(node_t** root);

#endif // !N_ARY_H