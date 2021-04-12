#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define SUCCESS 1
#define FAILURE 0

int removeNode(LIST *list, void *data);
void *retriveData(LIST *list, int position);
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

// Removes the first element from a list and returns its value
void *pop(LIST *list) {
  node_l *current_node = list->head;

  if (current_node != NULL) {
    void *data = current_node->data;

    if (removeNode(list, 0) == FAILURE)
      break;

    return data;
  } else
    return NULL;
}

// Removes a node from the list given the position
int removeNode(LIST *list, int position) {
  node_l *current_node = retrievNode(list, position);

  if (current_node != NULL) {
    if (current_node->prev == NULL)
      list->head = current_node->next;
    else
      current_node->prev->next = current_node->next;

    if (current_node->next == NULL)
      list->tail = current_node->prev;
    else
      current_node->next->prev = current_node->prev;

    free(current_node);
    current_node = NULL;
    return SUCCESS;
  } else
    return FAILURE;
}

// Retrievs the data from a node in a list given the position
void *retriveData(LIST *list, int position) {
  node_l *current_node = retrievNode(list, position);

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
