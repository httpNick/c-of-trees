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
    void * newChild;
    if (isGreater == -1) {

      if (n->left == NULL) {
        newChild = createAChild(n, x);
        if (newChild) n->left = newChild;
      } else {
        bstInsert(n->left, x);
      }

    } else if (isGreater == 1) {

      if (n->right == NULL) {
        newChild = createAChild(n, x);
        if(newChild) n->right = newChild;
      } else {
        bstInsert(n->right, x);
      }

    }

  } else{

    n = createAChild(NULL, x);

  }

  return n;
}

struct node * createAChild(struct node *par, int x) {

  struct node *n = malloc(
    sizeof(struct node)
  );
  if (n) {
    n->parent = par;
    n->left = n->right = NULL;
    n->val = x;
    n->color = RED;
  } else {
    // memory allocation failure
    return NULL;
  }

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

void freeTree(struct node **tree) {

  if (*tree == NULL) return;

  freeTree(&(*tree)->left);
  freeTree(&(*tree)->right);
  free(*tree);
  *tree = NULL;

}