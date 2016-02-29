#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "red-black.h"

struct node *createANode(int);

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

  root = NULL;

  struct node *testNodes[] = {
    createANode(6),
    createANode(2),
    createANode(1),
    createANode(20),
    createANode(30),
    createANode(15),
    createANode(16),
    NULL
  };

  int _i;
  for(_i = 0; ; _i++) {
    if (testNodes[_i] == NULL) break;
    root = insert(root, testNodes[_i]);
  }

  inOrderPrint(root);

  freeTree(&root);

  return 0;
}

struct node * createANode(int value) {

  struct node *n = malloc(
    sizeof(struct node)
  );

  if (n) {

    n->val = value;
    n->color = RED;
    n->parent = n->left = n->right = NULL;
    return n;

  } else {

    return NULL;

  }
}