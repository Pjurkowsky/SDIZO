#include "RedAndBlackTree.h"

RedAndBlackTree::RedAndBlackTree()
{
    nil = new Node(-1);
    nil->parent = nil;
    nil->right = nil;
    nil->left = nil;
    root = nil;
}

std::string RedAndBlackTree::toString()
{
    std::stringstream ss;
    inorderTraversal(root, ss);
    return ss.str();
}

void RedAndBlackTree::push(int data)
{
    Node *z = new Node(data);
    Node *x = root;
    Node *y = nil; // y will be parent of z

    while (x != nil)
    {
        y = x;
        if (z->key > x->key)
            x = x->right;
        else
            x = x->right;
    }

    z->parent = y;
    if (root == nil)
        root = z; // tree was empty

    if (z->key > y->key)
        y->right = z;
    else
        y->left = z;

    z->left = nil;
    z->right = nil;
    z->color = 'R';

    pushFix(z);
}

void RedAndBlackTree::pop(int data)
{
    Node *z = find(data);

    if (z == nil)
        return;

    if (z->left == nil && z->right == nil)
    {
        if (z == root)
            root = nil;
        else
        {
            if (z == z->parent->left)
                z->parent->left = nil;
            else
                z->parent->right = nil;
        }
        if (z->color == 'B')
            popFix(z);
        delete z;
        return;
    }
    if (z->left == nil || z->right == nil)
    {
        Node *child = z->left != nil ? z->left : z->right;
        if (z == root)
            root = child;
        else
        {
            if (z == z->parent->left)
                z->parent->left = child;
            else
                z->parent->right = child;
            child->parent = z->parent;
        }
        delete z;
        popFix(child);
        return;
    }
    else
    {
        Node *successor = findSuccessor(z);
        int tempKey = successor->key;
        pop(tempKey);
        z->key = tempKey;
    }
}

void RedAndBlackTree::pushFix(Node *z)
{
    while (z->parent->color == 'R' && z != root)
    {
        if (z->parent == z->parent->parent->left) // z parent a left child?
        {
            if (z->parent->parent->right->color == 'R') // are uncle and z both red?
            {
                z->parent->color = 'B';
                z->parent->parent->right->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                rightRotate(z->parent->parent);
            }
        }
        else // same as above but right and left are changed -> mirror
        {
            if (z->parent->parent->left->color == 'R')
            {
                z->parent->color = 'B';
                z->parent->parent->left->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                leftRotate(z->parent->parent);
            }
        }
        root->color = 'B';
    }
}
void RedAndBlackTree::popFix(Node *z)
{
    while (z != root && z->color == 'B')
    {
        if (z == z->parent->left)
        {
            Node *brother = z->parent->left;
            if (brother->color == 'R')
            {
                brother->color = 'B';
                z->parent->color = 'R';
                leftRotate(z->parent);
                brother = z->parent->right;
            }
            if (brother->left->color == 'B' && brother->right->color == 'B')
            {
                brother->color = 'R';
                z = z->parent;
            }
            else
            {
                if (brother->right->color == 'B')
                {
                    brother->left->color = 'B';
                    brother->color = 'R';
                    rightRotate(brother);
                    brother = z->parent->right;
                }
                brother->color = z->parent->color;
                z->parent->color = 'B';
                leftRotate(z->parent);
                z = root;
            }
        }
        else
        {
            Node *brother = z->parent->left;
            if (brother->color == 'R')
            {
                brother->color = 'B';
                z->parent->color = 'R';
                rightRotate(z->parent);
                brother = z->parent->left;
            }
            if (brother->right->color == 'B' && brother->left->color == 'B')
            {
                brother->color = 'R';
                z = z->parent;
            }
            else
            {
                if (brother->left->color == 'B')
                {
                    brother->right->color = 'B';
                    brother->color = 'R';
                    leftRotate(brother);
                    brother = z->parent->left;
                }
                brother->color = z->parent->color;
                z->parent->color = 'B';
                brother->left->color = 'B';
                rightRotate(z->parent);
                z = root;
            }
        }
    }
    z->color = 'B';
}

void RedAndBlackTree::leftRotate(Node *x)
{
    Node *y = x->right;
    x->right = y->left;

    if (y->left != nil)
        y->left->parent = x;
    y->parent = x->parent;

    if (x->parent == nil)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void RedAndBlackTree::rightRotate(Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    if (y->right != nil)
        y->right->parent = x;
    y->parent = x->parent;

    if (x->parent == nil)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;
    y->right = x;
    x->parent = y;
}

RedAndBlackTree::Node *RedAndBlackTree::findSuccessor(Node *x)
{
    if (x->right != nullptr)
    {
        Node *current = x->right;

        while (current->left != nil)
        {
            current = current->left;
        }
        return current;
    }
    else
    {
        Node *current = x;
        Node *y = x->parent;
        while (y != nullptr && current == y->right)
        {
            current = y;
            y = y->parent;
        }
        return y;
    }
}

RedAndBlackTree::Node *RedAndBlackTree::find(int data)
{
    Node *current = root;
    while (current != nullptr && current != nil && current->key != data)
    {
        if (data < current->key)
            current = current->left;
        else
            current = current->right;
    }

    return current;
}

void RedAndBlackTree::inorderTraversal(Node *root, std::stringstream &ss)
{
    if (root != nil)
    {
        inorderTraversal(root->left, ss);
        ss << root->key << " ";
        inorderTraversal(root->right, ss);
    }
}
