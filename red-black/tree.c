#include <stddef.h>
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

struct node * bstInsert(struct node *tree, int x) {}

struct node * insert(struct node *tree, int x) {}

void freeTree(struct node **tree) {}