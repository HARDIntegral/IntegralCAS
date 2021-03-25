#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <limits.h>

#include "symbols.h"
#include "n_ary.h"

// Just for testing the N-ary Tree
void parse() {
    node_t* root = initTree(INT_MIN, PLUS, 2);
    if (root == NULL) {
        printf("FATAL ERROR: fix dis\n");
        return;
    }
    addBranch(&root, 1, NONE, 3);
    addBranch(&root, 2, NONE, 0);
    addBranch(&(root->children[0]), 4, NONE, 0);
    addBranch(&(root->children[0]), 5, NONE, 0);
    addBranch(&(root->children[0]), 6, NONE, 0);

    printTree(&root);
}
