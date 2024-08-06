#include "rbtree.h"

#include <iostream>

void init(RBTree *tree) {
  tree->nil = new Node;
  tree->nil->color = BLACK;
  tree->root = tree->nil;
}

Node *rbTreeMinimum(RBTree *tree, Node *x) {
  while (x->left != tree->nil) {
    x = x->left;
  }
  return x;
}

Node *rbTreeMaximum(RBTree *tree, Node *x) {
  while (x->right != tree->nil) {
    x = x->right;
  }
  return x;
}

Node *rbTreeSuccessor(RBTree *tree, Node *x) {
  if (x->right != tree->nil) {
    return rbTreeMinimum(tree, x->right);
  }
  Node *y = x->parent;
  while (y != tree->nil && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

Node *rbTreePredecessor(RBTree *tree, Node *x) {
  if (x->left != tree->nil) {
    return rbTreeMaximum(tree, x->left);
  }
  Node *y = x->parent;
  while (y != tree->nil && x == y->left) {
    x = y;
    y = y->parent;
  }
  return y;
}

void leftRotate(RBTree *tree, Node *x) {
  Node *y = x->right;
  x->right = y->left;
  if (y->left != tree->nil) {
    y->left->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == tree->nil) {
    tree->root = y;
  } else if (x == x->parent->left) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }
  y->left = x;
  x->parent = y;
}

void rightRotate(RBTree *tree, Node *y) {
  Node *x = y->left;
  y->left = x->right;
  if (x->right != tree->nil) {
    x->right->parent = y;
  }
  x->parent = y->parent;
  if (y->parent == tree->nil) {
    tree->root = x;
  } else if (y == y->parent->left) {
    y->parent->left = x;
  } else {
    y->parent->right = x;
  }
  x->right = y;
  y->parent = x;
}

Node *treeSearch(Node **root, int key) {
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

Node *rbTreeSearch(RBTree *tree, int key) {
  Node *x = tree->root;
  while (x != tree->nil && x->key != key) {
    if (key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  return x;
}

void insertFixup(RBTree *tree, Node *z) {
  while (z->parent->color == RED) {
    if (z->parent == z->parent->parent->left) {
      Node *y = z->parent->parent->right;
      if (y->color == RED) {
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      } else {
        if (z == z->parent->right) {
          z = z->parent;
          leftRotate(tree, z);
        }
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        rightRotate(tree, z->parent->parent);
      }
    } else {
      Node *y = z->parent->parent->left;
      if (y->color == RED) {
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      } else {
        if (z == z->parent->left) {
          z = z->parent;
          rightRotate(tree, z);
        }
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        leftRotate(tree, z->parent->parent);
      }
    }
  }
  tree->root->color = BLACK;
}

void insertNode(RBTree *tree, int key) {
  Node *z = new Node;
  z->key = key;
  z->left = tree->nil;
  z->right = tree->nil;
  Node *y = tree->nil;
  Node *x = tree->root;
  while (x != tree->nil) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (y == tree->nil) {
    tree->root = z;
  } else if (z->key < y->key) {
    y->left = z;
  } else {
    y->right = z;
  }
  z->left = tree->nil;
  z->right = tree->nil;
  z->color = RED;
  insertFixup(tree, z);
}

void deleteFixup(RBTree *tree, Node *x) {
  while (x != tree->root && x->color == BLACK) {
    if (x == x->parent->left) {
      Node *w = x->parent->right;
      if (w->color == RED) {
        w->color = BLACK;
        x->parent->color = RED;
        leftRotate(tree, x->parent);
        w = x->parent->right;
      }
      if (w->left->color == BLACK && w->right->color == BLACK) {
        w->color = RED;
        x = x->parent;
      } else {
        if (w->right->color == BLACK) {
          w->left->color = BLACK;
          w->color = RED;
          rightRotate(tree, w);
          w = x->parent->right;
        }
        w->color = x->parent->color;
        x->parent->color = BLACK;
        w->right->color = BLACK;
        leftRotate(tree, x->parent);
        x = tree->root;
      }
    } else {
      Node *w = x->parent->left;
      if (w->color == RED) {
        w->color = BLACK;
        x->parent->color = RED;
        rightRotate(tree, x->parent);
        w = x->parent->left;
      }
      if (w->right->color == BLACK && w->left->color == BLACK) {
        w->color = RED;
        x = x->parent;
      } else {
        if (w->left->color == BLACK) {
          w->right->color = BLACK;
          w->color = RED;
          leftRotate(tree, w);
          w = x->parent->left;
        }
        w->color = x->parent->color;
        x->parent->color = BLACK;
        w->left->color = BLACK;
        rightRotate(tree, x->parent);
        x = tree->root;
      }
    }
  }
  x->color = BLACK;
}

Node *deleteNode(RBTree *tree, Node *z) {
  Node *x, *y;
  if (z->left == tree->nil || z->right == tree->nil) {
    y = z;
  } else {
    y = rbTreeSuccessor(tree, z);
  }
  if (y->left != tree->nil) {
    x = y->left;
  } else {
    x = y->right;
  }
  x->parent = y->parent;
  if (y->parent == tree->nil) {
    tree->root = x;
  } else if (y == y->parent->left) {
    y->parent->left = x;
  } else {
    y->parent->right = x;
  }
  if (y != z) {
    z->key = y->key;
  }
  if (y->color == BLACK) {
    deleteFixup(tree, x);
  }
  return y;
}

void printHelper(Node **root) {
  if (*root) {
    printHelper(&(*root)->left);
    std::cout << (*root)->key << " ";
    printHelper(&(*root)->right);
  }
}

void print(Node **root) {
  printHelper(root);
  std::cout << "\n";
}
