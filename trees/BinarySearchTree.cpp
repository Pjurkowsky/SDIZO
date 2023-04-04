#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : root(nullptr)
{
}

std::string BinarySearchTree::toString()
{
    std::stringstream ss;
    inorderTraversal(root, ss);
    return ss.str();
}

BinarySearchTree::~BinarySearchTree()
{
    deleteTree(root);
    root = nullptr;
}

void BinarySearchTree::push(int data)
{
    Node *parentNode = nullptr;
    Node *newNode = new Node(data);
    Node *tempNode = root;
    while (tempNode != nullptr) // szukamy rodzica dla naszego nowego node
    {
        parentNode = tempNode;
        if (newNode->key > tempNode->key)
            tempNode = tempNode->right;
        else
            tempNode = tempNode->left;
    }
    newNode->parent = parentNode;

    if (parentNode == nullptr) // jeżeli parentNode nie istnieje to ustawiamy nowego roota jako korzeń
        root = newNode;
    else if (newNode->key > parentNode->key) // jeżeli klucz jest wiekszy do idzie na prawo
        parentNode->right = newNode;
    else // jeżeli nie to w lewo
        parentNode->left = newNode;
}

void BinarySearchTree::pop(int data)
{
    deleteNode(root, data);
    // Node deleteNode = find(data);
    // Node tempNode = nullptr;
    // Node otherNode = nullptr;

    // if (deleteNode == nullptr)
    //     return;

    // if (deleteNode->left == nullptr || deleteNode->right == nullptr) // node posiada jednego syna
    //     tempNode = deleteNode;
    // else
    //     tempNode = findSuccessor(deleteNode); // jeżeli node posiada dwóch synów to szukamy następnika

    // if (tempNode->left != nullptr) // sprawdzanie ktorego syna posiada nastepnik lewego czy prawego
    //     otherNode = tempNode->left;
    // else
    //     otherNode = tempNode->right;

    // if (otherNode != nullptr)
    //     otherNode->parent = tempNode->parent;

    // if (tempNode->parent == nullptr) //
    //     root = otherNode;
    // else
    // {
    //     if (tempNode == tempNode->parent->left)
    //         tempNode->parent->left = otherNode;
    //     else
    //         tempNode->parent->right = otherNode;
    // }
    // if (tempNode != deleteNode)
    //     deleteNode->key = tempNode->key;
}

BinarySearchTree::Node *BinarySearchTree::find(int data)
{
    Node *tempNode = root;
    while (tempNode != nullptr || tempNode->key != data)
    {
        if (data > tempNode->key)
            tempNode = tempNode->right;
        else
            tempNode = tempNode->left;
    }
    return tempNode;
}

void BinarySearchTree::inorderTraversal(Node *root, std::stringstream &ss)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left, ss);
    ss << root->key << " ";
    inorderTraversal(root->right, ss);
}

void BinarySearchTree::deleteTree(Node *root)
{
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void BinarySearchTree::deleteNode(Node *node, int key)
{
}
