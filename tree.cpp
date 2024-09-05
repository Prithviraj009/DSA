#include<iostream>
#include<stack>
#include<queue>
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
    stack <Node *>S;
    queue <Node *> q;
    int level=0;
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
// Method to insert binary tree 
void BST(Node *current, Node *newNode) {
		if(newNode->data>current->data)
		{
			if(current->right== NULL)
				current->right=newNode;
			else
				insertNode(current->right,newNode);
		}
		if(newNode->data<current->data)
		{
			if(current->left== NULL)
				current->left=newNode;
			else
				insertNode(root->left,newNode);
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


void printPostorder (Node *root)
{
    if (root == NULL)
        return;

    // Recur on left subtree
    printPostorder(root->left);

    // Recur on right subtree
    printPostorder(root->right);

    // Deal with the node
    cout << root->data << " ";
}

void printInorder(Node *root)
{
    if (root == NULL)
        return;
    // Recur on left subtree
    printInorder(root->left);
	
    // Deal with the node
    cout << root->data << " ";

    // Recur on right subtree
    printInorder(root->right);
}
// inorder traversal using stack
void InorderStack()
{
    Node *temp=root;
     while(temp!=NULL || !S.empty())
    {
       while(temp!=NULL)
        { S.push(temp);
           temp=temp->left;
        }
           temp=S.top();
           S.pop();
           cout <<temp->data <<" ";
           temp=temp->right;
    }
}

//level order using queue not getting output
void printLevelOrder(Node *root)
{
	if(root==NULL) return;
	queue<Node *> Q;
	Q.push(root);
	while(!Q.empty())
	{
		Node *current=Q.front();
		cout<<current->data;
		if(current->left!=NULL)
		Q.push(current->left);
		if(current->right!=NULL)
		Q.push(current->right);
		Q.pop();
	}
}
void LevelOrder()
{
   printLevelOrder();
}
void Preorder()
{
   printPreorder(root);
}
void Postorder()
{  
   printPostorder(root);
}
void Inorder()
{
   printInorder(root);
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
	cout <<"preorder" <<endl;
	t1.Preorder();
	cout <<endl;
	cout <<"Inorder" <<endl;
    t1.Inorder();
    cout <<endl;
    cout <<"postorder" <<endl;
    t1.Postorder();
    cout <<"Inorder using stack" <<endl;
    t1.InorderStack();
    cout <<"level order using queue" << endl;
    t1.LevelOrder(10);    
}




