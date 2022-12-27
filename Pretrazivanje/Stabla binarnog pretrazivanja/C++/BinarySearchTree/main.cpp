#include "BinarySearchTree.h"

int main () {
    BST::BinarySearchTree bst;

    bst.insert(27);
    bst.insert(9);
    bst.insert(19);
    bst.insert(91);
    bst.insert(2);
    bst.insert(7);
    bst.insert(3);
    bst.insert(82);
    bst.insert(10);

    std::cout << bst.findSuccessor(bst.search(7))->key << std::endl;

    bst.remove(9);
    bst.remove(19);

    std::cout << bst << std::endl;
}