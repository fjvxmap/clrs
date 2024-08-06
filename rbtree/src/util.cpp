#include "util.h"

#include <iostream>

int getHeight(Node *node) {
  if (node == nullptr) {
    return 0;
  }
  int leftHeight = getHeight(node->left);
  int rightHeight = getHeight(node->right);
  return 1 + std::max(leftHeight, rightHeight);
}

int getBalanceFactor(Node *node) {
  if (node == nullptr) {
    return 0;
  }
  return getHeight(node->left) - getHeight(node->right);
}

void compareBalanceFactor(Node **rbRoot, Node **bstRoot) {
  int rbBalanceFactor = std::abs(getBalanceFactor(*rbRoot));
  int bstBalanceFactor = std::abs(getBalanceFactor(*bstRoot));

  std::cout << "RBTree Balance Factor: "
            << 1 - (double)rbBalanceFactor / getHeight(*rbRoot) << std::endl;
  std::cout << "BST Balance Factor: "
            << 1 - (double)bstBalanceFactor / getHeight(*bstRoot) << std::endl;
}
