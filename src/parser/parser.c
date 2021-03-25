#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <limits.h>

#include "symbols.h"
#include "n_ary.h"

// Just for testing the N-ary Tree
void parse() {
    int a = 1;
    OPERATOR b = PLUS;
    int c = 2;
    int d = 3;
    int e = 4;
    int f = 5;
    node_t* root = initTree(NULL, &b);
    node_t* tmp = addBranch(&root, &a, NULL);
    tmp = addBranch(&root, &c, NULL);
    tmp = addBranch(&(root->head->node), &d, NULL);
    tmp = addBranch(&(root->head->node), &e, NULL);
    tmp = addBranch(&(root->head->node), &f, NULL);
    printTree(root);
}
