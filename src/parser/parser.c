#include <math.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "../includes/binary.h"
#include "../includes/list.h"
#include "../includes/list_helpers.h"
#include "../includes/symbols.h"
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

  // Shunting-Yard
  LIST *token_intermediate = generateList();
  void *data = pop(token_list);
  while (data != NULL) {
    TRY {
      int integer_test = parseInteger((char *)data);
      append(token_intermediate, &integer_test);
    }
    CATCH(NOTANUMBEREXCEPTION) {
      OPERATOR OPER = PLUS;
      OPERATOR tmpOPER = OPER;
      append(token_intermediate, &tmpOPER);
    }
    CATCHALL { printf("FATAL ERROR\n"); }
    data = pop(token_list);
  }
  if (destroyList(token_list) == FAILURE)
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
