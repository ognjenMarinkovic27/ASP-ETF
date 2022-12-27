#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

namespace BST { 

struct Node;

class BinarySearchTree {
public:
    Node* search(int key);
    const Node* search(int key) const;

    Node* findMin();
    const Node* findMin() const;

    Node* findMax();
    const Node* findMax() const;

    Node* findSuccessor(Node* node);
    const Node* findSuccessor(Node* node) const;
    
    Node* findSuccessor() { return findSuccessor(root); }

    void insert(int key);
    void remove(int key);

    friend std::ostream& operator<<(std::ostream& os, const BinarySearchTree& bst);
private:
    Node* findMin(Node* root) const;
    Node* findMax(Node* root) const;

    Node* findInsertParent(int key) const;
    
    bool isLeaf(Node* node) const;
    void removeLeaf(Node* node);
    
    bool isOneChildedNode(Node* node);
    void removeOneChildedNode(Node* node);


    Node* root = nullptr;
};

struct Node {
    Node(int key) : key(key) {}

    int key;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
};

}

#endif