//
// Created by Nick Duncan on 2/25/16.
//

#ifndef C_OF_TREES_RED_BLACK_H
#define C_OF_TREES_RED_BLACK_H
#define RED 0
#define BLACK 1

struct node {
  int val;
  int color;
  struct node *parent;
  struct node *left;
  struct node *right;
};
// regular BST insert to be used in red-black's true insert.
struct node * bstInsert(struct node *, struct node *);
// true red-black insert that includes red-black tree rules.
struct node * insert(struct node *, struct node *);
struct node * grandparent(struct node *);
struct node * auntcle(struct node *);
void leftRotate(struct node *, struct node *);
void rightRotate(struct node *, struct node *);
void freeTree(struct node *);
void inOrderPrint(struct node *);

#endif //C_OF_TREES_RED_BLACK_H
