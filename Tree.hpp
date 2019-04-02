#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node* parent;

	Node(int x);
	// ~Node();
};

namespace ariel
{

class Tree
{
  private:
  int tree_size;
	void helpInsert(Node* myNode, Node* node,Node* parent);
	void helpPrint(Node* node);
	Node* catch_num(Node* node, int x);
	bool helpContains(Node* node,int x);


  public:
	Node* myroot;

	Tree();
	void clear(Node* node);
	void insert(int);
	void print();
	int parent(int x);
	int right(int x);
	int left(int x);
	int size();
	int root();
	bool contains(int x);
	void remove(int x);
	~Tree();
};
} // namespace ariel
