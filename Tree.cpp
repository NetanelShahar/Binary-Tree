#include <iostream>
#include "Tree.hpp"
#include <string.h>

using namespace std;
using namespace ariel;

Tree::Tree()
{
    myroot=NULL;
}

Tree::~Tree() {

	Remove_auxiliary_tree(myroot);
}



//Re-creation of leaves
Tree::node* Tree::Creat_Leaf(int x) {

	if(contains(x)==true) {
		throw std::invalid_argument("The number already exists in the tree");
		return NULL;
}
	node* N = new node;
	N->x = x;
	N->left = NULL;
	N->right = NULL;
	
	return N;
}

    void Tree::insert(int x) {

	}


    void Tree::print()
    {

    }



    
    int Tree::parent (int x)
    {
        return 0;
    }

    int Tree::right(int x)
    {
        return 0;
    }

	int Tree::left(int x)
    {
        return 0;
    }

	int Tree::size()
	{
        return 0;
    }
   
    int Tree::root()
	{
        return 0;
    }

bool Tree::contains(int x){

	return contains_Private(x, myroot);
}

    bool Tree::remove(int x)
    {
        return true;
    }

///////////////// - Auxiliary functions - /////////////////

bool Tree::contains_Private(int x,node* y){

//if the tree is empty return false
    if(y==NULL) {
        return false;
    }
   //if it found ->return true
    if(y->x==x) {
        return true;
    }
    //Recursive testing
    else if(x < y->x) {

        return contains_Private(x,y->left);
    } else  {

        return contains_Private(x,y->right); 

    }

}

void Tree::Remove_auxiliary_tree(node* N) {
//If it is not NULL
	if (N != NULL) {

		if (N->left != NULL){
			Remove_auxiliary_tree(N->left);
		}

		if (N->right != NULL)	{
			Remove_auxiliary_tree(N->right);
		}
//Print
		cout << "Deleting the node" << N->x << endl;

		delete N;
	}
}


