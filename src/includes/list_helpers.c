#include <stdio.h>
#include <stdlib.h>

#include "symbols.h"

void printString(void *input) {
  char *string = (char *)input;
  printf("%s ", string);
}

void printInteger(void *input) {
  int value = *(int *)input;
  printf("%d ", value);
}

void printOperator(void *input) {
  OPERATOR value = *(OPERATOR *)input;
  printf("%d ", value);
}
