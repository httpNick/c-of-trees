#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "red-black.h"

void handleCaseOne(struct node *, struct node *);
void handleCaseTwoAndThree(struct node *, struct node *, void(*)(struct node *, struct node *), void(*)(struct node *, struct node *));

struct node * grandparent(struct node * tree) {

  if((tree != NULL) && tree->parent != NULL) return tree->parent->parent;
  return NULL;

}

struct node * auntcle(struct node *tree) {

  struct node *gparent = grandparent(tree);

  if(gparent != NULL) {

    if (gparent->left != NULL && gparent->left->val == tree->parent->val) return gparent->right;
    else return gparent->left;

  }
  return NULL;

}

struct node * bstInsert(struct node * n, struct node * x) {

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

void inOrderPrint(struct node * tree) {

  if (tree != NULL) {

    inOrderPrint(tree->left);
    printf("value: %d | color: %d\n", tree->val, tree->color);
    inOrderPrint(tree->right);

  }

}

struct node * insert(struct node * root, struct node * x) {

  root = bstInsert(root, x);
  x->color = RED;

  // if x != root or 2nd child of tree.
  while(grandparent(x) != NULL && x->parent != NULL && x->parent->color == RED) {

    // ref grandparents other child.
    struct node *y = auntcle(x);
    if (y == NULL) break;
    // x's parent is left side of grandparent
    if (x->parent->val == grandparent(x)->left->val) {

      // case 1
      if (y->color == RED) {

       handleCaseOne(x, y);

      } else if (x->val == x->parent->right->val) {

        handleCaseTwoAndThree(root, x, leftRotate, rightRotate);

      }

    // x's parent is right side of grandparent.
    } else if (x->parent->val == grandparent(x)->right->val) {

      // case 1
      if (y->color == RED) {

        handleCaseOne(x, y);

      } else if (x->val == x->parent->left->val) {

        handleCaseTwoAndThree(root, x, rightRotate, leftRotate);

      }

    }

  }


  root->color = BLACK;
  return root;

}

void handleCaseOne(struct node * x, struct node * y) {

  x->parent->color = BLACK;
  y->color = BLACK;
  grandparent(x)->color = RED;
  x = grandparent(x);

}

void handleCaseTwoAndThree(struct node * root, struct node * x, void(*firstRotation)( struct node *, struct node *), void(*secondRotation)(struct node *, struct node *)) {

  // case 2
  x = x->parent;
  firstRotation(root, x);

  //case 3
  x->parent->color = BLACK;
  grandparent(x)->color = RED;
  secondRotation(root, grandparent(x));

}

void leftRotate(struct node * root, struct node * n) {
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

void freeTree(struct node * tree) {

  if (tree == NULL) return;

  freeTree(tree->left);
  freeTree(tree->right);
  free(tree);

}