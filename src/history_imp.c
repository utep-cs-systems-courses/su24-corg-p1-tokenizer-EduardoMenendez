#include "history.h"
#include <stdio.h>
#include <stdlib.h>

List* init_history(){
  List* history = (List*)malloc(sizeof(List));
  return history;
}

void add_history(List *list, char *str){
  Item* newNode = (Item*) malloc(sizeof(Item));
  newNode->str = str;
  newNode->next = NULL;
  if(list->root==NULL){
    newNode->id = 1;
    list->root = newNode;
  }else{
    Item* tail = getLastNode(list);
    newNode->id = (tail->id)+1;
    tail->next = newNode;
  }
}
void print_history(List* list){
  Item *curr = list->root;
  printf("\n\nHistory Items:\n");
  if(list->root == NULL){
    printf("\tThere are no items to show:(\n");
  }
  while (curr != NULL) {
    printf("\t%d: %s\n", curr->id, curr->str);
    curr = curr->next;
  }
}
char* get_history(List *list, int id){
  Item *curr = list->root;
  while(curr != NULL){
    if(curr->id == id) return curr->str;
    curr = curr->next;
  }
  return NULL;
}


void free_nodes(Item *node){
  if(node == NULL) return ;
  free_nodes(node->next);
  free(node);
}

void free_history(List *list){
  free_nodes(list->root);
  free(list);
}

Item* getLastNode(List *list){
  Item* curr = list->root; 
  while(curr->next != NULL){
    curr = curr->next;
  }
  return curr;
}


