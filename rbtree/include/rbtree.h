#include "bst.h"

typedef struct rbtree {
  Node *root;
  Node *nil;
} RBTree;

void init(RBTree *tree);

Node *rbTreeMinimum(RBTree *tree, Node *x);

Node *rbTreeMaximum(RBTree *tree, Node *x);

Node *rbTreeSuccessor(RBTree *tree, Node *x);

Node *rbTreePredecessor(RBTree *tree, Node *x);

void leftRotate(RBTree *tree, Node *x);

void rightRotate(RBTree *tree, Node *y);

Node *rbTreeSearch(RBTree *tree, int key);

void insertFixup(RBTree *tree, Node *z);

void insertNode(RBTree *tree, int key);

void deleteFixup(RBTree *tree, Node *x);

Node *deleteNode(RBTree *tree, Node *z);

void printHelper(RBTree *tree);

void print(RBTree *tree);
