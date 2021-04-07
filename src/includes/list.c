#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "../includes/symbols.h"

typedef enum {
    INT,
    CHAR,
    OPER
} TYPE;

typedef struct node_l node_l;
struct node_l {
    void* data;
    TYPE type;
    node_l* next;
};

node_l* createListNode(void* data, TYPE type) {
    node_l* new_node = (node_l*)malloc(sizeof(node_l));
    new_node->data = data;
    new_node->type = type;
    new_node->next = NULL;
    return new_node;
}

void pushNode(node_l** head, void* data, TYPE type) {
    node_l* new_node = createListNode(data, type);
    new_node->next = *head;
    *head = new_node;
}

void appendListNode(node_l** head, void* data, TYPE type) {
    node_l* tmp = *head;
    node_l* new_node = createListNode(data, type);
    if (tmp == NULL)
        *head = new_node;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_node;
    }
}

node_l* getNextNode(node_l* current_node) {
    return current_node->next;
}

void* returnValue(node_l* current_node) {
    return current_node->data;
}

void destroyList(node_l** head) {
    node_l* tmp = *head;
    while (1) {
        while (tmp->next != NULL)
            tmp = tmp->next;
        free(tmp->next);
        tmp->next = NULL;
        if (tmp != NULL)
            tmp = *head;
        else
            break;
        printf("test 2\n");
    }
}

void printList(node_l** head) {
    printf("test\n");
    node_l* tmp = *head;
    while (tmp != NULL) {
        switch (tmp->type) {
            case INT:
                printf("Value - %d\n", *(int*)(tmp->data));
                break;
            case CHAR:
                printf("Value - %s\n", (char*)(tmp->data));
                break;
            case OPER:
                printf("Value - %d\n", *(OPERATOR*)(tmp->data));
                break;
            default:
                printf("INVALID TYPE\n");
        }
        tmp = tmp->next;
    }
}
