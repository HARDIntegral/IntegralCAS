#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <limits.h>

#include "symbols.h"

typedef struct TreeNode node_t;
struct TreeNode {
    int value;
    OPERATOR symbol;
    node_t** children;
    int total_children;
    int availableBranches;
};

node_t* createTreeNode(int value, OPERATOR symbol, const int numInputs) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    if (node != NULL) {
        node->value = value;
        node->symbol = symbol;
        node->children = (node_t**)malloc(sizeof(node_t) * numInputs);
        node->total_children = numInputs;
        node->availableBranches = numInputs;
        return node;
    } else {
        printf("FATAL ERROR CREATING TREE NODE\n");
        return NULL;
    }
}

node_t* initTree(int value, OPERATOR symbol, const int numChildren) {
    node_t* root = createTreeNode(value, symbol, numChildren);
    if (root != NULL) {
        return root;
    } else {
        printf("FATAL ERROR CREATING TREE\n");
        return NULL;
    }
}

void addBranch(node_t** root, int value, OPERATOR symbol, const int numInputs) {
    if ((*root)->availableBranches > 0) {
        (*root)->availableBranches--;
        node_t* newBranch = createTreeNode(value, symbol, numInputs);
        (*root)->children[(*root)->total_children - (*root)->availableBranches - 1] = newBranch;
    }
}

void printTabs (int level) {
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    printf("\n");
}

void printTreeRecursive(node_t* root, int level) {
    if (root != NULL) {
        printTabs(level);
        if (root->value != INT_MIN)
            printf("Value - %d\n", root->value);
        else 
            printf("Symbol - %d\n", root->symbol);
        for (int i = 0; i < root->total_children - 1; i++) {
            node_t* nextBranch = root->children[i];
            printTreeRecursive(nextBranch, ++level);
        }
    }
}

void printTree(node_t* root) {
    if (root != NULL)
        printTreeRecursive(root, 0);
}