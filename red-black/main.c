#include <stddef.h>
#include <stdio.h>
#include "red-black.h"

int main() {

  struct node *root = NULL;

  struct node a = { .val = 1, .color = 0, .parent = NULL, .left = NULL, .right = NULL };
  struct node b = { .val = 2, .color = 1, .parent = NULL, .left = NULL, .right = NULL };
  struct node c = { .val = 3, .color = 2, .parent = NULL, .left = NULL, .right = NULL };
  struct node d = { .val = 4, .color = 0, .parent = NULL, .left = NULL, .right = NULL };

  b.left = &c;
  c.parent = &b;
  root = &a;
  root->left = &b;
  b.parent = &a;
  root->right = &d;
  d.parent = &a;

  printf("auntcle: %d\n", auntcle(&c)->val);
  printf("grandparent: %d\n", grandparent(&c)->val);

  freeTree(&root);
  root = NULL;

  int test[] = {6, 2, 1, 20, 30, 15, 16, -1};

  int i;
  for(i = 0; test[i] != -1; i++) {
    root = bstInsert(root, test[i]);
  }

  inOrderPrint(root);

  freeTree(&root);

  return 0;
}
