#include <iostream>
#include <string>

#include "rbtree.h"

int main() {
  RBTree *rbtree = new RBTree;
  Node *bstroot = nullptr;

  init(rbtree);

  std::string command;
  int key;
  while (std::cin >> command >> key) {
    if (command == "i") {
      insertNode(rbtree, key);
      bstInsert(&bstroot, key);
      // std::cout << "Inserted " << key << std::endl;
    } else if (command == "d") {
      Node *deleted;
      deleted = deleteNode(rbtree, rbTreeSearch(rbtree, key));
      free(deleted);
      deleted = bstDelete(&bstroot, treeSearch(&bstroot, key));
      free(deleted);
      // std::cout << "Deleted " << key << std::endl;
    } else {
      std::cerr << "Unknown command: " << command << std::endl;
    }
    // print(&rbroot);
  }
  compareBalanceFactor(&(rbtree->root), &bstroot);
  return 0;
}
