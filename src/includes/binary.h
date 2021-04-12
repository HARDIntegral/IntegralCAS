#ifndef BINARY_H
#define BINARY_H

typedef struct node_t node_t;

struct node_t {
  int *val_ptr;
  OPERATOR *oper_ptr;
  node_t *left_node;
  node_t *right_node;
};

node_t *addBranch(node_t **root, int *val_ptr, OPERATOR *oper_ptr);
node_t *initTree(int *val_ptr, OPERATOR *oper_ptr);

#endif // !BINARY_H
