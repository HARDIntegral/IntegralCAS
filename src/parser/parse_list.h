#ifndef PARSE_LIST_H
#define PARSE_LIST_H

#include "../includes/list.h"

typedef enum { INT, CHAR, OPER } TYPE;

typedef struct parse_list {
  LIST *data_list;
  LIST *type_list;
} parse_list;

// Generate a new Parse List
parse_list *generateParseList();

// Add values to the list
int pushParseList(parse_list *list, void *data, TYPE *_type);
int appendParseList(parse_list *list, void *data, TYPE *_type);

// Destructive getters
void popParseList(parse_list *list, void *data, TYPE *type_holder);

// Print contents of the list
void printParseList(parse_list *list);

// Free memory
int destroyParseList(parse_list *list);

#endif // PARSE_LIST_H
