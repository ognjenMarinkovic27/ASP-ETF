#include "BinarySearchTree.h"
#include <stdexcept>
#include <stack>

namespace BST {

Node* BinarySearchTree::findInsertParent(int key) const {

    Node* current = root;
    Node* parent = nullptr;

    while(current != nullptr) {
        parent = current;

        if(current->key == key)
            throw std::invalid_argument("Key already exists in Binary Search Tree.");

        if(key < current->key)
            current = current->left;
        else if(key > current->key)
            current = current->right;
    }

    return parent;
}

bool BinarySearchTree::isLeaf(Node* node) const {
    return !node->left && !node->right;
}

void BinarySearchTree::removeLeaf(Node* node) {
    Node* parent = node->parent;

    if(node == parent->left)
        parent->left = nullptr;
    else
        parent->right = nullptr;

    delete node;
}

bool BinarySearchTree::isOneChildedNode(Node* node) {
    return node->left && !node->right || !node->left && node->right;
}

void BinarySearchTree::removeOneChildedNode(Node* node) {
    Node* parent = node->parent;

    if(node->left) {
        if(parent && parent->left == node) parent->left = node->left;
        else if(parent && parent->left == node) parent->right = node->left;

        node->left->right = node->right;
        node->left->parent = parent;
    }
    else {
        if(parent && parent->left == node) parent->left = node->right;
        else if(parent && parent->left == node) parent->right = node->right;

        node->right->left = node->left;
        node->right->parent = parent;
    }

    delete node;
}

Node* BinarySearchTree::findMin(Node* root) const {
    Node* current = root;
    while(current->left)
        current = current->left;
    
    return current;
}

Node* BinarySearchTree::findMax(Node* root) const {
    Node* current = root;
    while(current->right)
        current = current->right;
    
    return current;
}

Node* BinarySearchTree::findMin() {
    return findMin(root);
}

const Node* BinarySearchTree::findMin() const {
    return findMin(root);
}

Node* BinarySearchTree::findMax() {
    return findMax(root);
}

const Node* BinarySearchTree::findMax() const {
    return findMin(root);
}

const Node* BinarySearchTree::findSuccessor(Node* node) const {
    Node* current = node;

    if(current->right != nullptr)
        return findMin(current->right);
    
    Node* parent = current->parent;
    while(parent != nullptr && current == parent->right) {
        current = parent;
        parent = current->parent;
    }
    return parent;
}

Node* BinarySearchTree::findSuccessor(Node* node) {
    return const_cast<Node*>(const_cast<const BinarySearchTree*>(this)->findSuccessor(node));
}

const Node* BinarySearchTree::search(int key) const {
    const Node* current = root;

    while(current != nullptr && key != current->key) {
        if(key < current->key)
            current = current->left;
        else if(key > current->key)
            current = current->right;
    }

    return current;
}

Node* BinarySearchTree::search(int key) {
    return const_cast<Node*>(const_cast<const BinarySearchTree*>(this)->search(key));
}

void BinarySearchTree::insert(int key) {

    Node* newNode = new Node(key);

    if(root == nullptr) {
        root = newNode;
        return;
    }

    Node* parent = findInsertParent(key);

    newNode->parent = parent;

    if(key < parent->key) parent->left = newNode;
    else parent->right = newNode;
}

void BinarySearchTree::remove(int key) {
    if(root == nullptr)
        throw std::logic_error("Binary Search Tree is empty");

    Node* current = search(key);

    if(current == nullptr)
        throw std::logic_error("Key not found in Binary Search Tree.");

    if(isLeaf(current)) {
        removeLeaf(current);
        return;
    }

    if(isOneChildedNode(current)) {
        removeOneChildedNode(current);
        return;
    }

    Node* successor = findSuccessor(current);

    std::swap(current->key, successor->key);

    if(isLeaf(successor))
        removeLeaf(successor);
    else
        removeOneChildedNode(successor);
}

std::ostream& operator<<(std::ostream& os, const BinarySearchTree& bst) {
    std::stack<Node*> visitStack;

    Node* current = bst.root;

    while (current != nullptr) {
        visitStack.push(current);
        current = current->left;
    }

    while(!visitStack.empty()) {
        current = visitStack.top();
        visitStack.pop();

        os << current->key << " ";
        current = current->right;

        while (current != nullptr) {
            visitStack.push(current);
            current = current->left;
        }
    }

    return os;
}

}