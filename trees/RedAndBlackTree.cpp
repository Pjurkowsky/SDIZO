#include "RedAndBlackTree.h"

RedAndBlackTree::RedAndBlackTree()
{
    nil = new Node(0);
    nil->color = 'B';
    root = nil;
}

RedAndBlackTree::~RedAndBlackTree()
{
    // delete all the nodes in the tree using post-order traversal
    while (root != nil)
        pop(root->key);

    // delete the sentinel node
    delete nil;
}

// return a string representation of the tree
std::string RedAndBlackTree::toString()
{
    std::stringstream ss;
    inorderTraversal(root, ss);
    return ss.str();
}

// displays the tree in pretty way
void RedAndBlackTree::display(const std::string &prefix, const Node *node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──");

        // print the value of the node
        std::cout << node->key << std::endl;

        // enter the next tree level - left and right branch
        display(prefix + (isLeft ? "│   " : "    "), node->left, true);
        display(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

// displays the tree in pretty way
void RedAndBlackTree::display()
{
    display("", root, false);
}
// inserting a node into the tree
void RedAndBlackTree::push(int data)
{
    Node *z = new Node(data);

    Node *y = nil;
    Node *x = root;

    while (x != nil) // Traverse the tree to find the correct position to insert the new node
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if (y == nil) // Set the root of the tree to z if y is nil
        root = z;
    else if (z->key < y->key) // Set z as the left child of y if z's key is less than y's key
        y->left = z;
    else // Otherwise, set z as the right child of y
        y->right = z;

    z->left = nil;
    z->right = nil;
    z->color = 'R';
    pushFix(z);
}

// fix the tree after insertion
void RedAndBlackTree::pushFix(Node *k)
{
    while (k->parent->color == 'R') // continue fixing the Red-Black Tree properties until the parent of k is black
    {
        if (k->parent == k->parent->parent->left) // if the parent of k is the left child of its parent
        {
            // y is the right sibling of k's parent
            Node *y = k->parent->parent->right;

            if (y->color == 'R') // case 1: k's uncle y is red
            {
                k->parent->color = 'B';
                y->color = 'B';
                k->parent->parent->color = 'R';
                k = k->parent->parent;
            }

            else // case 2: k's uncle y is black and k is a right child
            {
                if (k == k->parent->right)
                {
                    k = k->parent;
                    leftRotate(k);
                }
                // case 3: k's uncle y is black and k is a left child
                k->parent->color = 'B';
                k->parent->parent->color = 'R';
                rightRotate(k->parent->parent);
            }
        }
        else // if the parent of k is the right child of its parent
        {
            // y is the left sibling of k's parent
            Node *y = k->parent->parent->left;
            if (y->color == 'R') // case 1: k's uncle y is red
            {
                k->parent->color = 'B';
                y->color = 'B';
                k->parent->parent->color = 'R';
                k = k->parent->parent;
            }
            else // case 2: k's uncle y is black and k is a left child
            {
                if (k == k->parent->left)
                {
                    k = k->parent;
                    rightRotate(k);
                }
                // case 3: k's uncle y is black and k is a right child
                k->parent->color = 'B';
                k->parent->parent->color = 'R';
                leftRotate(k->parent->parent);
            }
        }
    }
    root->color = 'B';
}

// delete a node from the tree
void RedAndBlackTree::pop(int data)
{
    Node *z = find(data);

    // if node not found, return.
    if (z == nil)
        return;

    // otherwise, prepare to remove the node.
    Node *y = z;
    char yOriginalColor = y->color;
    Node *x;

    if (z->left == nil) // if the node has no left child, replace it with its right child.
    {
        x = z->right;
        transplant(z, z->right);
    }
    else if (z->right == nil) // if the node has no right child, replace it with its left child.
    {
        x = z->left;
        transplant(z, z->left);
    }
    else // otherwise, replace it with its successor and adjust the tree accordingly.
    {
        y = findSuccessor(z);
        yOriginalColor = y->color;
        x = y->right;

        if (y->parent == z) // if the successor is a direct child of the node to be removed, update its parent.
            x->parent = y;
        else // otherwise, replace the successor with its right child and update the tree.
        {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        // replace the node to be removed with its successor.
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    // if the original color of the removed node was black, fix the tree.
    if (yOriginalColor == 'B')
        popFix(x);

    delete z;
}

// fix the tree after deletion
void RedAndBlackTree::popFix(Node *x)
{
    while (x != root && x->color == 'B')
    {
        if (x == x->parent->left) // check if x is a left child of its parent
        {
            Node *w = x->parent->right; // store the sibling of x

            if (w->color == 'R') // case 1: if w is red, make it black and rotate left around x's parent
            {
                w->color = 'B';
                x->parent->color = 'R';
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == 'B' && w->right->color == 'B') // case 2: if both of w's children are black, set w to red and move up to x's parent
            {
                w->color = 'R';
                x = x->parent;
            }
            else // case 3: if w's right child is black, make w's left child black and rotate right around w
            {    //          then, set w to x's parent's right child and continue to case 4
                if (w->right->color == 'B')
                {
                    w->left->color = 'B';
                    w->color = 'R';
                    rightRotate(w);
                    w = x->parent->right;
                }
                // case 4: set w to the same color as x's parent, make x's parent black,
                //         make w's right child black, and rotate left around x's parent
                w->color = x->parent->color;
                x->parent->color = 'B';
                w->right->color = 'B';
                leftRotate(x->parent);
                x = root;
            }
        }
        else // check if x is a right child of its parent
        {
            Node *w = x->parent->left;
            if (w->color == 'R') // case 1: if w is red, make it black and rotate right around x's parent
            {

                w->color = 'B';
                x->parent->color = 'R';
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == 'B' && w->left->color == 'B') //  case 2: If both of w's children are black, set w to red and move up to x's parent
            {
                w->color = 'R';
                x = x->parent;
            }
            else // Case 3: if w's left child is black, make w's right child black and rotate left around w
            {    //          then, set w to x's parent's left child and continue to Case 4
                if (w->left->color == 'B')
                {
                    w->right->color = 'B';
                    w->color = 'R';
                    leftRotate(w);
                    w = x->parent->left;
                }
                // case 4: set w to the same color as x's parent, make x's parent black,
                //         make w's left child black, and rotate right around x's parent
                w->color = x->parent->color;
                x->parent->color = 'B';
                w->left->color = 'B';
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = 'B';
}

// find a node
typename RedAndBlackTree::Node *RedAndBlackTree::find(int data)
{
    Node *current = root;
    while (current != nil && current->key != data)
    {
        if (data < current->key)
            current = current->left;
        else
            current = current->right;
    }
    return current;
}

// traverse the tree in order
void RedAndBlackTree::inorderTraversal(Node *root, std::stringstream &ss)
{
    if (root != nil)
    {
        inorderTraversal(root->left, ss);
        ss << root->key << " ";
        inorderTraversal(root->right, ss);
    }
}

// rotate the tree to the left
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

// rotate the tree to the right
void RedAndBlackTree::rightRotate(Node *x)
{
    Node *y = x->left;
    x->left = y->right;

    if (y->right != nil)
        y->right->parent = x;

    y->parent = x->parent;

    if (x->parent == nil)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->right = x;
    x->parent = y;
}

// find the successor of a node
typename RedAndBlackTree::Node *RedAndBlackTree::findSuccessor(Node *x)
{
    if (x->right != nil)
    {
        Node *current = x->right;
        while (current->left != nil)
            current = current->left;

        return current;
    }
    else
    {
        Node *current = x->parent;
        while (current != nil && x == current->right)
        {
            x = current;
            current = current->parent;
        }
        return current;
    }
}

// transplant a node
void RedAndBlackTree::transplant(Node *u, Node *v)
{
    if (u->parent == nil)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    v->parent = u->parent;
}
