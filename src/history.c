#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "history.h"  // Include your own header file



/* Initialize the linked list to keep the history. */

List* init_history() {

  List *list = (List*)malloc(sizeof(List));

  if (list == NULL) {

    perror("Memory allocation failed");

    exit(EXIT_FAILURE);

  }

  list->root = NULL;

  return list;

}



/* Add a history item to the end of the list. */

void add_history(List *list, char *str) {

  Item *newItem = (Item*)malloc(sizeof(Item));

  if (newItem == NULL) {

    perror("Memory allocation failed");

    exit(EXIT_FAILURE);

  }

  newItem->id = 0; // You can generate a unique ID as needed.

  newItem->str = strdup(str); // Duplicate the string for storage.

  newItem->next = NULL;



  if (list->root == NULL) {

    list->root = newItem;

  } else {

    Item *current = list->root;

    while (current->next != NULL) {

      current = current->next;

    }
    current->next = newItem;

  }

}
char *get_history(List *list, int id) {

  Item *current = list->root;

  while (current != NULL) {

    if (current->id == id) {

      return current->str;

    }

    current = current->next;

  }

  return NULL; // Item with the given ID not found.

}



/* Print the entire contents of the list. */

void print_history(List *list) {

  Item *current = list->root;

  while (current != NULL) {

    printf("ID: %d, String: %s\n", current->id, current->str);

    current = current->next;

  }

}



/* Free the history list and the strings it references. */

void free_history(List *list) {

  Item *current = list->root;

  while (current != NULL) {

    Item *temp = current;

    current = current->next;

    free(temp->str);

    free(temp);

  }

  free(list);

}
