#include<iostream>
using namespace std;
class CompleteBinaryTree;
class Node {
	int data;
	Node *left;
	Node *right;
	friend class CompleteBinaryTree;
public :
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;

	}
};

// CompleteBinaryTree class representing a complete binary tree
class CompleteBinaryTree {
public:
	Node *root;

	// Constructor to initialize the tree
	CompleteBinaryTree() {
		root = NULL;

	}

// Method to insert a node into the tree
	void insert(int data) {
		Node *newNode = new Node(data);
		if (root == NULL) {
			root = newNode;

		}
		else {
			insertNode(root,newNode);
		}

	}

	// Helper method to insert a node into the tree
	void insertNode(Node *current, Node *newNode) {
		cout << "where to insert node left or right"<< newNode->data <<endl;
		char ch;
		cin >> ch;
		if(ch=='r')
		{
			if(current->right==NULL)
				current->right=newNode;
			else
				insertNode(current->right,newNode);
		}
		else if(ch=='l')
		{
			if(current->left==NULL)
				current->left=newNode;
			else
				insertNode(current->left,newNode);
		}
		else
		{
			return;
		}
	}
	
	void printPreorder(Node *root)
{
    if (root == NULL)
        return;

    // Deal with the node
    cout << root->data << " ";

    // Recur on left subtree
    printPreorder(root->left);

    // Recur on right subtree
    printPreorder(root->right);
}
	void Preorder()
{
   printPreorder(root);
}

};

int main()
{	
	CompleteBinaryTree t1;
	t1.insert(5);
	t1.insert(3);
	t1.insert(2);
	t1.insert(9);
	t1.insert(4);
	t1.insert(10);
	t1.Preorder();

}