#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};


namespace ariel{

	class Tree{
	public:
	Node* myroot;

	Tree();
	void insert(int);
	void print();
	int parent (int x);
	int right(int x);
	int left(int x);
	int size();
	int root();
	bool contains(int x);
	bool remove(int x);
	~Tree();
	};
}







