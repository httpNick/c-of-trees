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

    if (gparent->left->val == tree->parent->val) return gparent->right;
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
  x->color = RED;
  while(x->parent != NULL && x->parent->color == RED) {
    if (x->parent->val == grandparent(x)->left->val) {
      struct node *y = grandparent(x)->right;
      // case 1
      if (y->color == RED) {
        x->parent->color = BLACK;
        y->color = BLACK;
        grandparent(x)->color = RED;
        x = grandparent(x);
      }
      //case 2
    }
  }
  tree->color = BLACK;
  return tree;

}

void leftRotate(struct node * root, struct node *n) {
  struct node *y = n->right;
  n->right = y->left;
  if (y->left != NULL) y->left->parent = n;
  y->parent = n->parent;
  if(n->parent == NULL) root = y;
  else if(n->val == n->parent->left->val) n->parent->left = y;
  else n->parent->right = y;
  y->left = n;
  n->parent = y;
}

void rightRotate(struct node * root, struct node * n) {
  struct node *y = n->left;
  n->left = y->right;
  if (y->right != NULL) y->right->parent = n;
  y->parent = n->parent;
  if(n->parent == NULL) root = y;
  else if(n->val == n->parent->right->val) n->parent->right = y;
  else n->parent->left = y;
  y->right = n;
  n->parent = y;
}

void freeTree(struct node *tree) {

  if (tree == NULL) return;

  freeTree(tree->left);
  freeTree(tree->right);
  free(tree);

}