#include <math.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "../includes/binary.h"
#include "../includes/list.h"
#include "../includes/list_helpers.h"
#include "../includes/symbols.h"
#include "parse_list.h"
#include "tokenizer.h"

#define TRUE 1
#define FALSE 0

jmp_buf savebuf;
int exception_value = 0;
#define TRY if ((exception_value = setjmp(savebuf)) == 0)
#define CATCH(NUM) else if (exception_value == NUM)
#define CATCHALL else
#define THROW(NUM) longjmp(savebuf, NUM)
#define NOTANUMBEREXCEPTION 1

int parseInteger(char *input);

void parse(char *input) {
  LIST *token_list = tokenize(input);
  iterate(token_list, printString, FALSE);
  printf("\n");

  // Shunting-Yard
  parse_list *token_intermediate = generateParseList();
  node_l *tmp_token = token_list->head;
  while (tmp_token != NULL) {
    void *data = tmp_token->data;
    TRY {
      int integer_test = parseInteger((char *)data);
      if (appendParseList(token_intermediate, &integer_test, INT) == FAILURE)
        printf("FAILURE APPENDING INTEGER");
    }
    CATCH(NOTANUMBEREXCEPTION) {
      OPERATOR oper = PLUS;
      if (appendParseList(token_intermediate, &oper, OPER) == FAILURE)
        printf("FAILURE APPENDING OPERATOR");
    }
    CATCHALL { printf("FATAL ERROR\n"); }
    tmp_token = tmp_token->next;
  }
  printParseList(token_intermediate);
  printf("\n");
  if (destroyList(token_list) == FAILURE)
    printf("FAILURE DEALLOCATING LIST");
  if (destroyParseList(token_intermediate) == FAILURE)
    printf("FAILURE DEALLOCATING LIST");
}

int parseInteger(char *input) {
  int result = 0;
  int len = strlen(input);
  for (int i = 0; i < len; i++) {
    if (input[i] > 57 || input[i] < 48) {
      THROW(NOTANUMBEREXCEPTION);
    }
    result = result + (input[i] - 48) * (int)ceil(pow(10, len - i - 1));
  }
  return result;
}
