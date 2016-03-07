#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "red-black.h"

struct node *createANode(int);
struct node *createTree(struct node **);

int main() {

  struct node *root = NULL;

  // print testing for auntcle and grandparent functions.
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
// Print testing for tree creation and inOrderPrint.
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

  root = createTree(testNodes);

  inOrderPrint(root);

  freeTree(root);

  // Print testing for tree rotations.

  struct node *rotateTestNodes[] = {
    createANode(7),
    createANode(4),
    createANode(11),
    createANode(6),
    createANode(9),
    createANode(3),
    createANode(18),
    createANode(2),
    createANode(14),
    createANode(17),
    createANode(12),
    createANode(19),
    createANode(22),
    createANode(20),
    NULL
  };

  root = createTree(rotateTestNodes);

  inOrderPrint(root);
  printf("before rotation: %d\n", root->right->val);
  leftRotate(root, root->right);
  printf("after left: %d\n", root->right->val);
  rightRotate(root, root->right);
  printf("after right: %d\n", root->right->val);

  freeTree(root);

  //root = createTree(rotateTestNodes);





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

struct node * createTree(struct node **nodes) {

  printf("\n");
  printf("--------------------");
  printf("creating new tree");
  printf("--------------------");
  printf("\n\n");

  struct node *root = NULL;
  int _i;

  for (_i = 0; ; _i++) {
    if (nodes[_i] == NULL) break;
    root = insert(root, nodes[_i]);
  }

  return root;

}