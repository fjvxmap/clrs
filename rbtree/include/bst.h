#include "util.h"

Node *treeMinimum(Node *x);

Node *treeMaximum(Node *x);

Node *treeSuccessor(Node *x);

Node *treePredecessor(Node *x);

Node *treeSearch(Node **root, int key);

Node *bstSearch(Node **root, int key);

void bstInsert(Node **root, int key);

Node *bstDelete(Node **root, Node *z);
