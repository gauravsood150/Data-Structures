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

node* search(node* root,int val)
{
	if(root==NULL)
		return NULL;
	if(root->data==val)
		return root;
	if(root->data > val)
		return search(root->left,val);
	return search(root->right,val);
}

node* miniNode(node* root)
{
	if(root==NULL)
		return NULL;
	while(root->left!=NULL)
		root=root->left;
	return root;
}

void Transplant(node** root_ref, node* u,node* v)
{
	if(u->parent==NULL)
		*root_ref=v;
	else if(u->parent->left==u)
		u->parent->left=v;
	else if(u->parent->right==u)
		u->parent->right=v;
	if(v!=NULL)
		v->parent=u->parent;
}

void deleteNode(node** root_ref, node* z)
{
	if(z==NULL)
		return;
	if(z->left==NULL)
		Transplant(root_ref, z, z->right);
	else if(z->right==NULL)
		Transplant(root_ref, z, z->left);
	else
	{
		node *y=miniNode(z->right);
		if(y->parent!=z)
		{
			Transplant(root_ref,y,y->right);
			y->right=z->right;
			y->right->parent=y;
		}
		Transplant(root_ref,z,y);
		y->left=z->left;
		y->left->parent=y;
	}
	delete(z);
}

int getheight(node* root)
{
	if(root==NULL)
		return 0;
	int l=getheight(root->left);
	int r=getheight(root->right);
	return (l>r?l:r) +1;
}

int main()
{
	node* root=NULL;
	insert(&root, 10);
	insert(&root, 15);
	insert(&root, 5);
	insert(&root, 20);
	insert(&root, 21);
	insert(&root, 8);
	insert(&root, 2);
	insert(&root, 12);
	inorder(root);
	int noToBeDeleted;
	do{
		std::cout<<std::endl;
		std::cin>>noToBeDeleted;
		node* toBeDeleted=search(root,noToBeDeleted);
		deleteNode(&root, toBeDeleted);
		inorder(root);
		//std::cout<<std::endl<<getheight(root);
		if(root!=NULL)
			std::cout<<std::endl<<root->data<<std::endl;
	}
	while(noToBeDeleted!=-1 && toBeDeleted!=NULL);
}

