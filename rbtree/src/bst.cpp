#include "bst.h"

Node *treeMinimum(Node *x) {
  while (x->left) {
    x = x->left;
  }
  return x;
}

Node *treeMaximum(Node *x) {
  while (x->right) {
    x = x->right;
  }
  return x;
}

Node *treeSuccessor(Node *x) {
  if (x->right) {
    return treeMinimum(x->right);
  }
  Node *y = x->parent;
  while (y && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

Node *treePredecessor(Node *x) {
  if (x->left) {
    return treeMaximum(x->left);
  }
  Node *y = x->parent;
  while (y && x == y->left) {
    x = y;
    y = y->parent;
  }
  return y;
}

Node *bstSearch(Node **root, int key) {
  Node *x = *root;
  while (x && x->key != key) {
    if (key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  return x;
}

void bstInsert(Node **root, int key) {
  Node *z = new Node;
  z->key = key;
  z->left = nullptr;
  z->right = nullptr;
  Node *y = nullptr;
  Node *x = *root;
  while (x) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (y == nullptr) {
    *root = z;
  } else if (z->key < y->key) {
    y->left = z;
  } else {
    y->right = z;
  }
}

Node *bstDelete(Node **root, Node *z) {
  if (z == nullptr) {
    return nullptr;
  }
  Node *y, *x;
  if (z->left == nullptr || z->right == nullptr) {
    y = z;
  } else {
    y = treeSuccessor(z);
  }
  if (y->left) {
    x = y->left;
  } else {
    x = y->right;
  }
  if (x) {
    x->parent = y->parent;
  }
  if (y->parent == nullptr) {
    *root = x;
  } else if (y == y->parent->left) {
    y->parent->left = x;
  } else {
    y->parent->right = x;
  }
  if (y != z) {
    z->key = y->key;
  }
  return y;
}
