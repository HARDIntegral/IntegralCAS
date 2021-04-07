#ifndef LIST_H
#define LIST_H

typedef enum {
    INT,
    CHAR,
    OPER
} TYPE;
typedef struct node_l node_l;

void pushNode(node_l** head, void* data, TYPE type);
void appendListNode(node_l** head, void* data, TYPE type);
node_l* getNextNode(node_l* current_node);
void* returnValue(node_l* current_node);
void destroyList(node_l** head);
void printList(node_l** head);

#endif //LIST_H
