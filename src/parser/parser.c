#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <limits.h>

#include "symbols.h"
#include "binary.h"

// Just for testing the N-ary Tree
void parse(char** input) {
    printf("%s\n", *input);
    OPERATOR a = PLUS;
    int b = 5342;
    int c = 54543;
    int d = 423;
    int e = 422;
    int f = 89;

    node_t* root = initTree(NULL, &a);
    addBranch(&root, &b, NULL);
    addBranch(&root, &c, NULL);
    addBranch(&(root->left_node), &d, NULL);
    addBranch(&(root->left_node), &e, NULL);
    addBranch(&(root->left_node->right_node), &f, NULL);

    printTree(root);
}
