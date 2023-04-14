#include "AVLTree.h"

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree()
{
    while (root) // delete the tree
        pop(root->key);
}

std::string AVLTree::toString()
{
    std::stringstream ss;
    inorderTraversal(root, ss);
    return ss.str();
}

void AVLTree::display(const std::string &prefix, const Node *node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──");
        std::cout << node->key << std::endl;
        display(prefix + (isLeft ? "│   " : "    "), node->left, true);
        display(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void AVLTree::display()
{
    display("", root, false);
}

void AVLTree::push(int data)
{
    Node *newNode = new Node(data);

    // if tree is empty, new node is the root
    if (root == nullptr)
    {
        root = newNode;
        return;
    }

    Node *currentNode = root;
    Node *parentNode = nullptr;

    // traverse the tree to find the position to insert the new node
    while (currentNode != nullptr)
    {
        parentNode = currentNode;
        if (newNode->key < currentNode->key)
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;
    }

    // insert the new node as a child of the parent node
    newNode->parent = parentNode;
    if (newNode->key < parentNode->key)
        parentNode->left = newNode;

    else
        parentNode->right = newNode;

    // update the height of the nodes from the new node to the root
    currentNode = newNode;
    while (currentNode != nullptr)
    {
        int balance = (currentNode->left ? currentNode->left->height : -1) -
                      (currentNode->right ? currentNode->right->height : -1);
        if (balance > 1)
        {
            if (currentNode->left->left && (!currentNode->left->right ||
                                            currentNode->left->left->height > currentNode->left->right->height))
                rightRotate(currentNode);

            else
            {
                leftRotate(currentNode->left);
                rightRotate(currentNode);
            }
        }
        else if (balance < -1)
        {
            if (currentNode->right->right && (!currentNode->right->left ||
                                              currentNode->right->right->height > currentNode->right->left->height))
                leftRotate(currentNode);

            else
            {
                rightRotate(currentNode->right);
                leftRotate(currentNode);
            }
        }
        currentNode->height = std::max((currentNode->left ? currentNode->left->height : -1),
                                       (currentNode->right ? currentNode->right->height : -1)) +
                              1;
        currentNode = currentNode->parent;
    }
}

void AVLTree::pop(int data)
{
    Node *nodeToDelete = find(data);
    if (nodeToDelete == nullptr)
        return;

    if (nodeToDelete->left && nodeToDelete->right)
    {
        // find the successor and replace the node to delete with it
        Node *successor = nodeToDelete->right;
        while (successor->left)
            successor = successor->left;
        nodeToDelete->key = successor->key;
        nodeToDelete = successor;
    }
    Node *childNode = (nodeToDelete->left ? nodeToDelete->left : nodeToDelete->right);
    if (childNode != nullptr) // update the child node parent
        childNode->parent = nodeToDelete->parent;

    if (nodeToDelete->parent == nullptr) // node to delete is the root
        root = childNode;
    else if (nodeToDelete == nodeToDelete->parent->left)
        nodeToDelete->parent->left = childNode;
    else
        nodeToDelete->parent->right = childNode;

    // update the height of the nodes from the child node to the root
    Node *currentNode = childNode;
    while (currentNode != nullptr)
    {
        int balance = (currentNode->left ? currentNode->left->height : -1) -
                      (currentNode->right ? currentNode->right->height : -1);
        if (balance > 1)
        {
            if (currentNode->left->left && (!currentNode->left->right ||
                                            currentNode->left->left->height > currentNode->left->right->height))
                rightRotate(currentNode);
            else
            {
                leftRotate(currentNode->left);
                rightRotate(currentNode);
            }
        }
        else if (balance < -1)
        {
            if (currentNode->right->right && (!currentNode->right->left ||
                                              currentNode->right->right->height > currentNode->right->left->height))
                leftRotate(currentNode);
            else
            {
                rightRotate(currentNode->right);
                leftRotate(currentNode);
            }
        }
        currentNode->height = std::max((currentNode->left ? currentNode->left->height : -1),
                                       (currentNode->right ? currentNode->right->height : -1)) +
                              1;
        currentNode = currentNode->parent;
    }

    delete nodeToDelete;
}
AVLTree::Node *AVLTree::find(int data)
{
    Node *currentNode = root;
    while (currentNode != nullptr && currentNode->key != data)
    {
        if (data < currentNode->key)
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;
    }
    return currentNode;
}

void AVLTree::inorderTraversal(Node *root, std::stringstream &ss)
{
    if (root == nullptr)
        return;
    inorderTraversal(root->left, ss);
    ss << root->key << " ";
    inorderTraversal(root->right, ss);
}

void AVLTree::leftRotate(Node *x)
{
    Node *y = x->right;
    x->right = y->left;

    if (y->left != nullptr)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
    // update the height of the nodes
    x->height = std::max((x->left ? x->left->height : -1), (x->right ? x->right->height : -1)) + 1;
    y->height = std::max((y->left ? y->left->height : -1), (y->right ? y->right->height : -1)) + 1;
}
void AVLTree::rightRotate(AVLTree::Node *x)
{
    Node *y = x->left;
    x->left = y->right;

    if (y->right != nullptr)
        y->right->parent = x;

    y->parent = x->parent;

    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->right = x;
    x->parent = y;
    // update the height of the nodes
    x->height = std::max((x->left ? x->left->height : -1), (x->right ? x->right->height : -1)) + 1;
    y->height = std::max((y->left ? y->left->height : -1), (y->right ? y->right->height : -1)) + 1;
}