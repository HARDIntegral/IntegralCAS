#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#include "symbols.h"

typedef struct node_t node_t;
struct node_t {
  int *val_ptr;
  OPERATOR *oper_ptr;
  node_t *left_node;
  node_t *right_node;
};

node_t *addBranch(node_t **root, int *val_ptr, OPERATOR *oper_ptr) {
  node_t *branch = (node_t *)malloc(sizeof(node_t));
  if (branch != NULL) {
    branch->val_ptr = val_ptr;
    branch->oper_ptr = oper_ptr;
    branch->left_node = NULL;
    branch->right_node = NULL;
    if (root != NULL) {
      if ((*root)->left_node == NULL)
        (*root)->left_node = branch;
      else if ((*root)->right_node == NULL)
        (*root)->right_node = branch;
    }
    return branch;
  }
  return NULL;
}

node_t *initTree(int *val_ptr, OPERATOR *oper_ptr) {
  return addBranch(NULL, val_ptr, oper_ptr);
}

void printTabs(int level) {
  for (int i = 0; i < level; i++) {
    printf("\t");
  }
}
