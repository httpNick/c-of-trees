#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "red-black.h"

struct node * grandparent(struct node *tree) {

  if((tree != NULL) && tree->parent != NULL) return tree->parent->parent;
  return NULL;

}

struct node * auntcle(struct node *tree) {

  struct node *gparent = grandparent(tree);

  if(gparent != NULL) {

    if (gparent->left == tree->parent) return gparent->right;
    else return gparent->left;

  }
  return NULL;

}

struct node * bstInsert(struct node *n, int x) {

  if (n != NULL) {

    int isGreater = (x < n->val) ? -1 : (x > n->val);

    if (isGreater == -1) {

      if (n->left == NULL) {
        n->left = createAChild(n, n->left, x);
      } else {
        bstInsert(n->left, x);
      }

    } else if (isGreater == 1) {

      if (n->right == NULL) {
        n->right = createAChild(n, n->right, x);
      } else {
        bstInsert(n->right, x);
      }

    }

  } else{

    n = createAChild(NULL, n, x);

  }

  return n;
}

struct node * createAChild(struct node *par, struct node *n, int x) {

  n = malloc(
    sizeof(struct node)
  );
  n->parent = par;
  n->left = n->right = NULL;
  n->val = x;
  n->color = RED;

  return n;

}

void inOrderPrint(struct node *tree) {

  if (tree != NULL) {

    inOrderPrint(tree->left);
    printf("value: %d | color: %d\n", tree->val, tree->color);
    inOrderPrint(tree->right);

  }

}

struct node * insert(struct node *tree, int x) {}

void freeTree(struct node **tree) {}