#include <stdio.h>
#include <stdlib.h>

#include "../includes/symbols.h"
#include "../includes/binary.h"
#include "../includes/stack.h"
#include "tokenizer.h"

void parse(char** input) {
    token* token_list = tokenize(*input);
    printTokens(token_list);

    // Shunting-Yard
    
}
