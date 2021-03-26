#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <limits.h>

#include "symbols.h"

typedef struct tree_node node_t;
typedef struct list_node node_l;

void addElement(node_l** head, node_t** branch);

struct tree_node {
    int* value_ptr;
    OPERATOR* oper_ptr;
    node_l* head;
};

struct list_node {
    node_t* node;
    node_l* next;
};

node_t* addBranch(node_t** root, int* value_ptr, OPERATOR* oper_ptr) {
    node_t* branch = (node_t*)malloc(sizeof(node_t));
    if (branch != NULL) {
        branch->value_ptr = value_ptr;
        branch->oper_ptr = oper_ptr;
        branch->head = NULL;
        if(root != NULL) {
            addElement(&((*root)->head), &branch);
        }
        return branch;
    }
    return NULL;
}

node_t* initTree(int* value_ptr, OPERATOR* oper) {
    node_t* root = addBranch(NULL, value_ptr, oper);
    return root;
}

void printTabs (int level) {
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
}

void printTreeRecursive(node_t* root, int level) {
    if (root != NULL) {
        printTabs(level);
        if (root->value_ptr != NULL)
            printf("Value - %d\n", *(root->value_ptr));
        else if(root->oper_ptr != NULL)
            printf("Operation - %d\n", *(root->oper_ptr));

        node_l* tmp = root->head;
        while (tmp != NULL) {
            printTreeRecursive(tmp->node, level + 1);
            tmp = tmp->next;
        }
    }
}

void printTree(node_t* root) {
    printTreeRecursive(root, 0);
}

node_l* createElement(node_t** branch) {
    node_l* element = (node_l*)malloc(sizeof(node_l));
    if (element != NULL) {
        element->node = *branch;
        element->next = NULL;
        return element;
    } else {
        return NULL;
    }
}

void addElement(node_l** head, node_t** branch) {
    node_l* tmp = *head;
    node_l* new = createElement(branch);
    if (new == NULL)
        return;
    if (tmp == NULL)
        *head = new;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
}