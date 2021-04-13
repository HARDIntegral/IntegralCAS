#include <malloc.h>
#include <stdlib.h>

#include "list.h"

node_l *retriveNode(LIST *list, int position);

// Initialize a new list
LIST *generateList() {
  LIST *new_list = (LIST *)malloc(sizeof(LIST));
  if (new_list != NULL) {
    new_list->size = 0;
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
  } else {
    return NULL;
  }
}

// Initialize a new node
node_l *generateNode(void *data) {
  node_l *new_node = (node_l *)malloc(sizeof(node_l));
  if (new_node != NULL) {
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
  } else {
    return NULL;
  }
}

// Push a node to the beginning of a list
int push(LIST *list, void *data) {
  node_l *new_node = generateNode(data);

  if (new_node != NULL) {
    if (list->size == 0)
      list->tail = new_node;
    else {
      list->head->prev = new_node;
      new_node->next = list->head;
    }
    list->head = new_node;
    list->size++;
    return SUCCESS;
  } else
    return FAILURE;
}

// Append a node to the end of a list
int append(LIST *list, void *data) {
  node_l *new_node = generateNode(data);

  if (new_node != NULL) {
    if (list->size == 0)
      list->head = new_node;
    else {
      list->tail->next = new_node;
      new_node->prev = list->tail;
    }
    list->tail = new_node;
    list->size++;
    return SUCCESS;
  } else
    return FAILURE;
}

// Returns the data from the head of the list
void *getHead(LIST *list) {
  if (list->head != NULL)
    return list->head->data;
  else
    return NULL;
}

// Returns the data from the tail of the list
void *getTail(LIST *list) {
  if (list->tail != NULL)
    return list->tail->data;
  else
    return NULL;
}

// Removes the first element from a list and returns its value
void *pop(LIST *list) {
  node_l *current_node = list->head;
  do {
    if (current_node != NULL) {
      void *data = current_node->data;

      if (removeNode(list, 0) == NULL)
        break;

      return data;
    }
  } while (0);
  return NULL;
}

// Removes the last element from a list and returns its value

void *snip(LIST *list) {
  node_l *current_node = list->tail;
  do {
    if (current_node != NULL) {
      void *data = current_node->data;

      if (removeNode(list, list->size - 1) == NULL)
        break;

      return data;
    }
  } while (0);
  return NULL;
}

// Removes a node from the list given the position
void *removeNode(LIST *list, int position) {
  node_l *current_node = retriveNode(list, position);

  if (current_node != NULL) {
    if (current_node->prev == NULL)
      list->head = current_node->next;
    else
      current_node->prev->next = current_node->next;

    if (current_node->next == NULL)
      list->tail = current_node->prev;
    else
      current_node->next->prev = current_node->prev;

    void *data = current_node->data;

    free(current_node);
    current_node = NULL;
    return data;
  } else
    return NULL;
}

// Retrievs the data from a node in a list given the position
void *retriveData(LIST *list, int position) {
  node_l *current_node = retriveNode(list, position);

  if (current_node != NULL)
    return current_node->data;
  else
    return NULL;
}

// Retrievs a node from a list given the position
node_l *retriveNode(LIST *list, int position) {
  if (position > list->size)
    return NULL;

  node_l *current_node;
  int current_positon;
  int reverse;

  if (position > (list->size - 1) / 2) {
    reverse = 1;
    current_positon = list->size - 1;
    current_node = list->tail;
  } else {
    reverse = 0;
    current_positon = 0;
    current_node = list->head;
  }

  while (current_node != NULL) {
    if (current_positon == position)
      break;

    current_node = (reverse ? (current_node->prev) : (current_node->next));
    current_positon = (reverse ? (current_positon - 1) : (current_positon + 1));
  }

  return current_node;
}

// Iterate through a list with a given function
void iterate(LIST *list, void (*fn)(void *), int reverse) {
  if (list != NULL) {
    node_l *current_node = (reverse ? list->tail : list->head);

    while (current_node != NULL) {
      (*fn)(current_node->data);
      current_node = (reverse ? (current_node->prev) : (current_node->next));
    }
  }
}

// Returns the length of the list
int length(LIST *list) {
  if (list != NULL) {
    node_l *current_node = list->head;
    int counter = 0;

    while (current_node != NULL) {
      counter++;
      current_node = current_node->next;
    }

    return counter;
  } else
    return -1;
}

// Destroys the list and frees its memory
int destroyList(LIST *list) {
  if (list == NULL)
    return FAILURE;
  node_l *head = list->head;
  node_l *tmp;

  while (tmp != NULL) {
    tmp = head->next;
    free(head);
    head = tmp;
  }
  head = NULL;

  free(list);
  list = NULL;
  return SUCCESS;
}
