#include <stdio.h>
#include <string.h>

#include "../includes/list.h"

void addToken(LIST *list, char *token) { append(list, token); }

LIST *tokenize(char *input) {
  LIST *token_list = generateList();

  if (token_list == NULL)
    return NULL;

  char *str_token = strtok(input, "\{} ");
  while (str_token != NULL) {
    addToken(token_list, str_token);
    str_token = strtok(NULL, "\{} ");
  }

  return token_list;
}
