#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct node {
	int data;
	struct node *left, *right;
};

node* newnode(int key){
	node *temp = new node;
	temp->data = key;
	temp->left = temp->right = NULL;
	return temp;
}

void reverse_level_order(node* root){
	stack<node*> stck;
	queue<node*> q;
	
	q.push(root);
	
	while(!q.empty()){
		node *temp;
		temp = q.front();
		q.pop();
		if(temp->left){
			q.push(temp->left);
			
		}
		if(temp->right){
			q.push(temp->right);
			
		}
		stck.push(temp);
	}
	while(!stck.empty()){
		node *temp;
		temp = stck.top();
		cout<<temp->data<<" ";
		stck.pop();
	}
	return;
}

int main(){
	node* root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->right->left = newnode(6);
	root->right->right = newnode(7);
	root->left->left->left = newnode(11);
	root->left->left->right = newnode(12);
	
	reverse_level_order(root);
	return 0;
}