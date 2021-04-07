#ifndef TOKEN_H
#define TOKEN_H

#include "../includes/list.h"

node_l* tokenize(char* input);
void* returnToken(node_l* current_node);
void clearTokens(node_l** token_head);
void printTokens(node_l** token_head);

#endif // !TOKEN_H
