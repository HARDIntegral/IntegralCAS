#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#include "../includes/list.h"
#include "../includes/list_helpers.h"
#include "../includes/symbols.h"
#include "parse_list.h"

#define SUCCESS 1
#define FAILURE 0

parse_list *generateParseList() {
  parse_list *new_parse_list = (parse_list *)malloc(sizeof(parse_list));

  LIST *new_data_list = (LIST *)malloc(sizeof(LIST));
  LIST *new_type_list = (LIST *)malloc(sizeof(LIST));

  if (new_parse_list == NULL)
    return NULL;
  if (new_data_list == NULL)
    return NULL;
  if (new_type_list == NULL)
    return NULL;

  new_data_list->size = 0;
  new_data_list->head = NULL;
  new_data_list->tail = NULL;

  new_type_list->size = 0;
  new_type_list->head = NULL;
  new_type_list->tail = NULL;

  new_parse_list->data_list = new_data_list;
  new_parse_list->type_list = new_type_list;

  return new_parse_list;
}

int pushParseList(parse_list *list, void *data, TYPE _type) {
  if (list == NULL)
    return FAILURE;
  if (list->data_list == NULL)
    return FAILURE;
  if (list->type_list == NULL)
    return FAILURE;

  push(list->data_list, data);
  push(list->type_list, &_type);

  return SUCCESS;
}

int appendParseList(parse_list *list, void *data, TYPE _type) {
  if (list == NULL)
    return FAILURE;
  if (list->data_list == NULL)
    return FAILURE;
  if (list->type_list == NULL)
    return FAILURE;

  append(list->data_list, data);
  append(list->type_list, &_type);

  return SUCCESS;
}

void printParseList(parse_list *list) {
  if (list == NULL)
    return;

  node_l *tmp_data = list->data_list->head;
  node_l *tmp_type = list->type_list->head;

  while (tmp_data != NULL && tmp_type != NULL) {
    switch (*(TYPE *)(tmp_type->data)) {
    case (INT):
      printf("%d ", *(int *)(tmp_data->data));
      break;
    case (CHAR):
      printf("%s ", (char *)(tmp_data->data));
      break;
    case (OPER):
      printf("%d ", *(OPERATOR *)(tmp_data->data));
    }
    tmp_data = tmp_data->next;
    tmp_type = tmp_type->next;
  }
}

int destroyParseList(parse_list *list) {
  if (list == NULL)
    return FAILURE;
  if (list->data_list == NULL)
    return FAILURE;
  if (list->type_list == NULL)
    return FAILURE;

  if (destroyList(list->data_list) == FAILURE)
    return FAILURE;
  if (destroyList(list->type_list) == FAILURE)
    return FAILURE;

  free(list);
  list = NULL;

  return SUCCESS;
}
