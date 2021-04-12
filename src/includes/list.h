#ifndef LIST_H
#define LIST_H

#define SUCCESS 1
#define FAILURE 0

typedef struct node_l {
  void *data;
  struct node_l *next;
  struct node_l *prev;
} node_l;

typedef struct list {
  int size;
  node_l *head;
  node_l *tail;
} LIST;

// Generate a list
LIST *generateList();

// Add values to the list
int push(LIST *list, void *data);
int append(LIST *list, void *data);

// Non-destructive getters
void *getHead(LIST *list);
void *getTail(LIST *list);
void *retriveData(LIST *list, int position);

// Destructive getters
void *pop(LIST *list);
void *snip(LIST *list);
void *removeNode(LIST *list, int position);

// Iterate through the list
void iterate(LIST *list, void (*fn)(void *), int reverse);
int length(LIST *list);

// Free memory
int destroyList(LIST *list);

#endif // LIST_H
