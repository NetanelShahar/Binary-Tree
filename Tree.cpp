#include <iostream>
#include "Tree.hpp"
#include <string.h>

using namespace std;
using namespace ariel;

Node::Node(int x)
{
    this->data = x;
    this->left = this->right = this->parent = NULL;
}
Tree::Tree()
{
    Tree::myroot = NULL;
    tree_size = 0;
    
}

Tree::~Tree()
{

    // Remove_auxiliary_tree(myroot);
}

//Re-creation of leaves
// Tree::node *Tree::Creat_Leaf(int x)
// {

// 	if(contains(x)==true) {
// 		throw std::invalid_argument("The number already exists in the tree");
// 		return NULL;
// }
// 	node* N = new node;
// 	N->x = x;
// 	N->left = NULL;
// 	N->right = NULL;

// 	return N;
// }
///////////////////////////////////////////////////////
//  if (tree_size == 0)
//     {
//         this->myroot = newNode;
//         this->tree_size++;
//         return;

void Tree::insert(int x)
{
    if (!contains(x))
        return;
    Node* newNode = new Node(x);

    if (tree_size == 0)
    {
        this->myroot = newNode;
        this->tree_size++;
        return;
    }
    helpInsert(newNode, myroot, NULL);
}

void Tree::helpInsert(Node *newNode, Node *localNode, Node *parent)
{

    if (localNode == NULL)
    {
        localNode=newNode;
        newNode->parent = parent;
        if(newNode->data>parent->data)
        {
            parent->right=newNode;
        }else
        {
            parent->left=newNode;
        }
        
        this->tree_size++;
    return;
    }else{
    if (newNode->data < localNode->data)
    {
        helpInsert(newNode, localNode->left, localNode);
    }
    if (newNode->data > localNode->data)
    {
        helpInsert(newNode, localNode->right, localNode);
    }}
}

void Tree::print() ///print in-order
{
    helpPrint(myroot);
}
void Tree::helpPrint(Node *node)
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

int Tree::parent(int x)
{
    //////lets throw an exception if the root is null/////////////
    if (contains(x))
        // cout<<"firsssssssssssssssssssssssst";
        return catch_num(myroot, x).parent->data;
    //   cout<<"lasssssssssssssssssssssssssst";
    return 0;
}

int Tree::right(int x)
{
    //////lets throw an exception if the root is null/////////////
    if (contains(x))
        return catch_num(myroot, x).right->data;
    return 0;
}

int Tree::left(int x)
{
    //////lets throw an exception if the root is null/////////////
    if (contains(x))
        return catch_num(myroot, x).left->data;
    return 0;
}

Node Tree::catch_num(Node *node, int x)
{

    // if(!contains(x))
    //     return;
    if (node->data == x)
        return *node;
    if (x < node->data)
        return catch_num(node->left, x);
    return catch_num(node->right, x);
}

int Tree::size()
{

    return tree_size;
}

int Tree::root()
{
    return this->myroot->data;
}

bool Tree::contains(int x)
{

    // return contains_Private(x, myroot);
    return true;
}

bool Tree::remove(int x)
{
    return true;
}

///////////////// - Auxiliary functions - /////////////////

// bool Tree::contains_Private(int x,node* y){

// //if the tree is empty return false
//     if(y==NULL) {
//         return false;
//     }
//    //if it found ->return true
//     if(y->x==x) {
//         return true;
//     }
//     //Recursive testing
//     else if(x < y->x) {

//         return contains_Private(x,y->left);
//     } else  {

//         return contains_Private(x,y->right);

//     }

// }

// void Tree::Remove_auxiliary_tree(node* N) {
// //If it is not NULL
// 	if (N != NULL) {

// 		if (N->left != NULL){
// 			Remove_auxiliary_tree(N->left);
// 		}

// 		if (N->right != NULL)	{
// 			Remove_auxiliary_tree(N->right);
// 		}
// //Print
// 		cout << "Deleting the node" << N->x << endl;

// 		delete N;
// 	}
// }
