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

struct node * bstInsert(struct node *n, struct node *x) {

  if (n != NULL) {

    int isGreater = (x->val < n->val) ? -1 : (x->val > n->val);
    if (isGreater == -1) {

      if (n->left == NULL) {
        x->parent = n;
        n->left = x;
      } else {
        bstInsert(n->left, x);
      }

    } else if (isGreater == 1) {

      if (n->right == NULL) {
        x->parent = n;
        n->right = x;
      } else {
        bstInsert(n->right, x);
      }

    }

  } else{

    n = x;

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

struct node * insert(struct node *tree, struct node *x) {

  tree = bstInsert(tree, x);
  printf("inserted node is: %d\n", x->val);
  if (x->parent != NULL) printf("inserted node's par is: %d\n", x->parent->val);
  return tree;

}

void freeTree(struct node **tree) {

  if (*tree == NULL) return;

  freeTree(&(*tree)->left);
  freeTree(&(*tree)->right);
  free(*tree);
  *tree = NULL;

}