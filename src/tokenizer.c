#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"


int space_char(char c) {

  return (c == ' ' || c == '\t');

}



int non_space_char(char c) {

  return !space_char(c);

}



char *token_start(char *str) {

  while (*str != '\0' && space_char(*str)) {

    str++;

  }

  return (*str != '\0') ? str : NULL;

}

char *token_terminator(char *token) {

  while (*token != '\0' && non_space_char(*token)) {

    token++;

  }

  return token;

}



int count_tokens(char *str) {

  int count = 0;

  char *token = token_start(str);



  while (token != NULL) {

    count++;

    token = token_start(token_terminator(token));

  }



  return count;

}

char *copy_str(char *inStr, short len) {

  char *copy = (char *)malloc(len + 1);

  if (copy == NULL) {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);

  }
  strncpy(copy, inStr, len);
  copy[len] = '\0';
  return copy;

}



char **tokenize(char *str) {

  int numTokens = count_tokens(str);
  char **tokens = (char **)malloc((numTokens + 1) * sizeof(char *));

  if (tokens == NULL) {

    perror("Memory allocation failed");
    exit(EXIT_FAILURE);

  }

  int tokenIndex = 0;
  char *token = token_start(str);

  while (token != NULL) {

    char *term = token_terminator(token);
    int len = term - token;

    tokens[tokenIndex] = copy_str(token, len);
    tokenIndex++;
    token = token_start(term);

  }
  tokens[numTokens] = NULL; // Null-terminate the array of tokens

  return tokens;

}



void print_tokens(char **tokens) {

  for (int i = 0; tokens[i] != NULL; i++) {

    printf("Token %d: %s\n", i, tokens[i]);

  }

}



void free_tokens(char **tokens) {

  for (int i = 0; tokens[i] != NULL; i++) {

    free(tokens[i]);

  }

  free(tokens);

}
