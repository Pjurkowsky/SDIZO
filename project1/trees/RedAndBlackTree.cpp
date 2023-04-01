#include "RedAndBlackTree.h"

RedAndBlackTree::RedAndBlackTree() : root(nullptr)
{
}

std::string RedAndBlackTree::toString()
{
    return std::string();
}

void RedAndBlackTree::push(int data)
{
    // Node *newNode = new Node(data);
    // newNode->left = nullptr;
    // newNode->right = nullptr;
    // newNode->parent = root;
    // if (newNode->parent == nullptr) // newNode staje sie korzeniem
    //     root = x;
    // else
    //     while (true)
    //     {
    //         if (newNode->parent->key > data)
    //             if (newNode->parent->left == nullptr)
    //             {
    //                 newNode->parent->left = newNode;
    //                 break;
    //             }
    //             newNode->parent = newNode->parent->left;
    //     }
}

void RedAndBlackTree::pop(int data)
{
}

RedAndBlackTree::Node* RedAndBlackTree::find(int number)
{
    return new Node(number);
}
