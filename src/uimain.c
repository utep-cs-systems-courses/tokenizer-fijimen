#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h" 

int menuOpt(char *str) {

  if (str[0] == 's') {

    return 1;

  } else if (str[0] == '2') {

    return 2;

  } else if (str[0] == '3') {

    return 3;

  } else {

    return -1;

  }

}
int word_length(char *str)
{
  char *tmpS = token_start(str);
  char *tmpE = token_terminator(tmpS);
  int i = 0;
  int length = 0;
  length = tmpE - tmpS;
  //     printf("the size was %d",length);
  return length;
}

int main() {

  int i;
  List *history = init_history();
  char str[100];
  int numHistory;
  char *strHistory;
  printf("Hello! Please enter one of the following characters:\n");

  while (1) {
    
    printf("1. Enter 's' to type and record your sentence\n2. Enter '!' followed by a number to display a certain sentence from history\n3. Enter 'h' to display all recorded sentences\n ");

    printf("$ ");
    fgets(str, 100, stdin);
    i = menuOpt(str);
    
    switch (i) {

    case 1:

      printf("Please enter your sentence:\n$");
      fgets(str, 100, stdin);
      str[strlen(str) - 1] = '\0'; // Remove the trailing newline character
      char **tokens = tokenize(str);
      printf("\n");
      print_tokens(tokens);
      add_history(history, str); // Store the original sentence, not the tokens
      free_tokens(tokens);
      break;

    case 2:

      if (str[0] == 'h' || str[0] == 'H') {

	print_history(history);

      } else {

	int historyIndex = atoi(str + 1);

	strHistory = get_history(history, historyIndex);

	if (strHistory == NULL) {

	  printf("Sentence not found in history.\n");

	} else {

	  printf("History %d: %s\n", historyIndex, strHistory);

	}

      }

      break;
      
    case 3:

	  printf("Thank you, Goodbye!\n");

	  free_history(history);

	  return 0;



	  default:

	    printf("Sorry, that was not a valid option please try again.\n");

	    break;

      }
  }

}
