#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

struct node{
	int data;
	node *next;
};

struct node* addnode(int data){
	struct node* temp = new node();
	temp->data = data;
	temp->next = NULL;
	return temp;
}

struct node* Kreverse(struct node* head, int k){
	struct node* curr = head;
	struct node* next = NULL;
	struct node* prev = NULL;
	int count = 0;
	
	while(curr != NULL && count<k){
		next = curr->next; 
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	
	if(next != NULL){
		head->next = Kreverse(next, k);
	}
	return prev;
}

void printList(struct node* head){
	while(head->next!=NULL){
		head = head->next;
		cout<<"->"<<head->data;
	}
	cout<<endl;
}

int main(){
	struct node *head = addnode(1);
	head->next = addnode(2);
	head->next->next = addnode(3);
	head->next->next->next = addnode(4);
	head->next->next->next->next = addnode(5);
	head->next->next->next->next->next = addnode(6);
	head->next->next->next->next->next->next = addnode(7);
	
	cout<<"Original List: "<<head->data;
	printList(head);
	int k = 3;
	cout<<"K = "<<k<<endl;

	struct node* temp = Kreverse(head, k);
	cout<<"K-Reversed List : "<<temp->data;
	printList(temp);
	return 0;
}