#ifndef LIST_H
#define LIST_H

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

LIST *generateList();

int push(LIST *list, void *data);
int append(LIST *list, void *data);
void *pop(LIST *list);
void *snip(LIST *list);

#endif // LIST_H
