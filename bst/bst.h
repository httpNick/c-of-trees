//
// Created by Nick Duncan on 2/23/16.
//

#ifndef C_OF_TREES_BST_H
#define C_OF_TREES_BST_H

struct bstNode {
  char * word;
  int count;
  struct bstNode *left;
  struct bstNode *right;
};

struct bstNode *addToTree(struct bstNode *, char *);
void inOrderPrint(struct bstNode *);
void preOrderPrint(struct bstNode *);
void postOrderPrint(struct bstNode *);
struct bstNode *find(struct bstNode *, char *);
void freeTree(struct bstNode **);

#endif //C_OF_TREES_BST_H
