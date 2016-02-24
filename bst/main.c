#include <stddef.h>
#include <stdio.h>
#include "bst.h"

int main() {

  struct bstNode *root = NULL;
  char * test[] = {"test", "hello", "world", "abc", "lol", "trees", "something", "abc", NULL};
  int i;

  for(i = 0; test[i] != NULL; i++) {
    root = addToTree(root, test[i]);
  }

  inOrderPrint(root);

  return 0;

}