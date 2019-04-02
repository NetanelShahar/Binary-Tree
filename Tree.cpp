#include <iostream>
#include "Tree.hpp"
#include <string.h>

#include <iostream>
#include <cmath>
#include <cassert>
#include <string>

using namespace std;
using namespace ariel;

Node::Node(int x)
{
    this->data = x;
    this->left = this->right = this->parent = NULL;
}

// Node::~Node()
// {
//     delete this;
// }

Tree::Tree() //constructor for Tree
{
    Tree::myroot = NULL;
    tree_size = 0;
}

Tree::~Tree() //destructor for Tree
{
    if (myroot == nullptr)
        return;
    clear(myroot);
}

void Tree::clear(Node *node) //a recursive function that clear the tree from the leaves to the root.
{
    if (node->left != nullptr)
        return clear(node->left);
    if (node->right != nullptr)
        return clear(node->right);
    delete node;
}

void Tree::insert(int x) // insert a node to the tree. It use the helpInsert function.
{
    if (contains(x)) //checks if we alredy have the value.
    {
        throw string("this tree does alredy contains ");
        return;
    }
    Node *newNode = new Node(x);

    if (tree_size == 0) //if the tree is empty so the node gets into the root.
    {
        this->myroot = newNode;
        this->tree_size++;
        return;
    }
    helpInsert(newNode, myroot, NULL);
}

void Tree::helpInsert(Node *newNode, Node *localNode, Node *parent) //a recursive method that checks whre should be the new node and insert it.
{

    if (localNode == NULL) //if we got into null so the new node should be there.
    {
        localNode = newNode;
        newNode->parent = parent;
        if (newNode->data > parent->data) //connect the relevant child to the parent.
        {
            parent->right = newNode;
        }
        else
        {
            parent->left = newNode;
        }

        this->tree_size++;
        return;
    }
    else
    {
        if (newNode->data < localNode->data)
        {
            helpInsert(newNode, localNode->left, localNode);
        }
        if (newNode->data > localNode->data)
        {
            helpInsert(newNode, localNode->right, localNode);
        }
    }
}

void Tree::print() ///print in-order. It use with helpPrint method//
{
    helpPrint(myroot);
}
void Tree::helpPrint(Node *node) // a recursive method for printing in-order.
{
    if (node == NULL)
        return;
    if (node->left != NULL)
    {
        helpPrint(node->left);
    }
    cout << node->data << endl;
    if (node->right != NULL)
    {
        helpPrint(node->right);
    }
}

int Tree::parent(int x) // looking for a specific node and return the value of it's parent.
{
    if (!contains(x))
        throw string("this tree does not contains ");
    return catch_num(myroot, x)->parent->data;
}

int Tree::right(int x) // looking for a specific node and return the value of it's right child.
{
    if (!contains(x))
        throw string("this tree does not contains ");
    return catch_num(myroot, x)->right->data;
}

int Tree::left(int x) // looking for a specific node and return the value of it's left child.
{
    if (!contains(x))
        throw string("this tree does not contains ");
    ;
    return catch_num(myroot, x)->left->data;
}

Node *Tree::catch_num(Node *node, int x) // a recursive method that gets a value and return the relevant node of it.
{
    if (node->data == x)
        return node;
    if (x < node->data)
        return catch_num(node->left, x);
    return catch_num(node->right, x);
}

int Tree::size() //check how items we have in our tree.
{

    return tree_size;
}

int Tree::root() // returns the value of the root
{
    return this->myroot->data;
}

bool Tree::contains(int x) //check if our tree contains some value. It use the helpContains method.
{
    return helpContains(myroot, x);
}
bool Tree::helpContains(Node *node, int x) // a recursive method that check if our tree contains some value.
{
    if (myroot == NULL)
    {
        return false;
    }

    if (node->data == x)
    {
        return true;
    }

    if (x < node->data)
    {
        if (node->left == NULL)
            return false;
        return helpContains(node->left, x);
    }
    else
    {
        if (node->right == NULL)
            return false;
    }
    return helpContains(node->right, x);
}

void Tree::remove(int x) //a method for removing some elements from our tree.
{
        cout<<"remove"<<endl;

    if (!contains(x))
    {
        throw string("this tree does not contains ");
        return;
    }
    Node* target = catch_num(myroot, x);

    //Node *target = &target;
    if (target->left == NULL && target->right == NULL) //////case 1
    {
        if (target->parent->left==target) {
            target->parent->left=NULL;
        }else{target->parent->right=NULL;}
        
        delete target;
        target = nullptr;
        tree_size--;
        return ;
    }
    if (((target->left == NULL) || (target->right == NULL)) && (target->parent->left == target)) ////case 2.1             
    {
        if (target->left != NULL)
        {
            target->parent->left = target->left;
            target->left->parent = target->parent;
            delete target;
        }
        if (target->right != NULL)
        {
            target->parent->left = target->right;
            target->right->parent = target->parent;
            delete target;
        }
    }

    if (((target->left == NULL) || (target->right == NULL)) && (target->parent->right == target)) ////case 2.2
    {
        if (target->left != NULL)
        {
            target->parent->right = target->left;
            target->left->parent = target->parent;
            delete target;
        }
        if (target->right != NULL)
        {
            target->parent->right = target->right;
            target->right->parent = target->parent;
            delete target;
        }
    }
}
