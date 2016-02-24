// a basic BST.
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

struct bstNode *addToTree(struct bstNode *thing, char *word) {

  if (thing != NULL) {

    int comp = strcmp(word, thing->word);
    if (comp == 0) thing->count++;
    else if (comp < 0) thing->left = addToTree(thing->left, word);
    else thing->right = addToTree(thing->right, word);

  } else {

    thing = malloc(
      sizeof(struct bstNode)
    );
    thing->word = strdup(word);
    thing->count = 1;
    thing->left = thing->right = NULL;

  }

return thing;

}

struct bstNode *find(struct bstNode *thing, char *word) {

  if (thing != NULL) {

    int comp = strcmp(word, thing->word);
    if(comp == 0) return thing;
    else if (comp < 0) thing = find(thing->left, word);
    else thing = find(thing->right, word);

  }

  return thing;
}

void inOrderPrint(struct bstNode *tree) {

  if (tree != NULL) {

    inOrderPrint(tree->left);
    printf("word: %s | count: %d\n", tree->word, tree->count);
    inOrderPrint(tree->right);

  }

}

void preOrderPrint(struct bstNode *tree) {

  if (tree != NULL) {

    printf("word: %s | count: %d\n", tree->word, tree->count);
    inOrderPrint(tree->left);
    inOrderPrint(tree->right);

  }

}

void postOrderPrint(struct bstNode *tree) {

  if (tree != NULL) {

    inOrderPrint(tree->left);
    inOrderPrint(tree->right);
    printf("word: %s | count: %d\n", tree->word, tree->count);

  }

}