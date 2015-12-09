#include<iostream>
#include<vector>
using namespace std;

struct node{
	int data;
	struct node *left, *right;
};

struct node* newNode(int data){
	struct node *temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

bool leaf(struct node* x){
	if(!x->left && !x->right)
		return true;
	return false;
}

void leftBoundary(struct node *root){
	struct node *temp = root;
	while(1){
		if(temp->left != NULL)
			temp = temp->left;
		else
			temp = temp->right;
			
		if (leaf(temp)) break;
		cout<<" "<<temp->data;
	}
	return;
}

void leafNodes(struct node *root){
	if(root == NULL)
		return;
	if(leaf(root))
		cout<<" "<<root->data;
	else{
		leafNodes(root->left);
		leafNodes(root->right);
	}
	return;
}

void rightBoundary(struct node* root){
	if(leaf(root))	return;
	if(root->right){
		rightBoundary(root->right);
	} 
	else if(root->left)
		rightBoundary(root->left);
	cout<<" "<<root->data;
	return;
}

int main(){
	struct node *root = newNode(20);
	root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
    
    cout<<"Boundary Traversal in anticlockwise manner: "<<root->data;
    
    leftBoundary(root);
    leafNodes(root);
    rightBoundary(root->right);
    
	return 0;
}