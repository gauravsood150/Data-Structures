#include <iostream>

struct node
{
	int data;
	node* left;
	node* right;
	node* parent;
};

node* createTNode(int data, node* left=NULL, node* right=NULL, node* parent=NULL)
{
	node* root=new node;
	root->data=data;
	root->left=left;
	root->right=right;
	root->parent=parent;
	return root;
}

void insertHelper(node** root_ref, int data, node* parent=NULL)
{
	if(*root_ref==NULL)
	{
		*root_ref=createTNode(data,NULL,NULL,parent);
		return;
	}
	if(data < (*root_ref)->data)
		insertHelper(&((*root_ref)->left), data, *root_ref);
	else
		insertHelper(&((*root_ref)->right), data, *root_ref);
}

void insert(node** root_ref, int data)
{
	insertHelper(root_ref, data, NULL);
}

void inorder(node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	std::cout<<root->data<<" ";
	inorder(root->right);
}

int main()
{
	node* root=NULL;
	insert(&root, 10);
	insert(&root, 15);
	insert(&root, 5);
	insert(&root, 20);
	insert(&root, 8);
	insert(&root, 2);
	insert(&root, 12);
	inorder(root);

}

