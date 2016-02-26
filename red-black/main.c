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

  printf("%d\n", auntcle(&c)->val);
  freeTree(&root);

  return 0;
}
