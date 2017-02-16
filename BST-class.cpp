#include <iostream>
#include <queue>

class node
{
public:
	int data;
	node* left;
	node* right;
	node* parent;
	node(int data, node* parent=NULL, node* left=NULL, node* right=NULL)
	{
		this->data=data;
		this->left=left;
		this->right=right;
		this->parent=parent;
	}
};

class BST
{
private:
	void _insert(int, node*);
	void _printInorder(node*);
public:
	node* root;

	BST()
	{
		root=NULL;
	}
	void insert(int);
	void printInorder();
	void levelOrder();

};

void BST::insert(int data)
{
	if(this->root==NULL)
	{
		(this->root)=new node(data);
		return;
	}
	else
		_insert(data,this->root);
}

void BST::_insert(int data, node* root)
{
	if(data < root->data)
	{
		if (root->left==NULL)
			{
				(root->left)=new node(data,root);
			}
		else
			_insert(data, root->left);
	}
	else
	{
		if(root->right==NULL)
			(root->right)= new node(data,root);
		else
			_insert(data, root->right);
	}
}

void BST::printInorder()
{
	_printInorder(root);
}

void BST::_printInorder(node* root)
{
	if(root==NULL)
		return;
	_printInorder(root->left);
	std::cout<<root->data<<" ";
	_printInorder(root->right);
}

void BST::levelOrder()
{
	std::queue<node* > Q;
	Q.push(root);
	Q.push(NULL);
	while(!Q.empty())
	{
		node* temp=Q.front();
		Q.pop();
		if(temp!=NULL)
		{
			std::cout<<temp->data<<" ";
			if(temp->left) Q.push(temp->left);
			if(temp->right) Q.push(temp->right); 
		}
		else
		{
			if(!Q.empty())
				Q.push(NULL);
			std::cout<<std::endl;
		}
	}
}

int main()
{
	BST r;
	r.insert(25);
	r.insert(16);
	r.insert(18);
	r.insert(12);
	r.insert(36);
	r.insert(30);
	r.insert(40);
	r.printInorder();
	std::cout<<std::endl;
	r.levelOrder();
	return 0;
}
