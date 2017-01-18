#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node *link;
}NODE;
NODE* getnode(){
	NODE *n=(NODE*)malloc(sizeof(NODE));
	return n;
}
NODE* insertFront(NODE *root){
	NODE *n=getnode();
	printf("\nEnter info : ");
	scanf("%d",&n->info);
	if(root==NULL)
		return n;
	n->link=root;
	return n;
}
NODE* insertRear(NODE *root){
	NODE *n=getnode(),*first=root;
	n->link=NULL;
	printf("\nEnter info :");
	scanf("%d",&n->info);
	if(root==NULL)
		return n;
	while(first->link!=NULL)
		first=first->link;
	first->link=n;
	return root;
}
NODE* deleteFront(NODE* root){
	NODE *temp;
	if(root==NULL){
		printf("\nUnderFlow");
		return NULL;
	}
	temp=root;
	root=root->link;
	free(temp);
	return root;
}
NODE* deleteRear(NODE* root){
	NODE *first=root,*temp;
	if(root==NULL){
		printf("\nUnderFlow");
		return NULL;
	}
	if(root->link==NULL){
		free(root);
		return NULL;
	}
	while(first->link->link!=NULL)
		first=first->link;
	temp=first->link->link;
	first->link=NULL;
	free(temp);
	return root;
}
NODE * deleteAny(NODE *root){
	NODE *first=root,*temp=NULL;
	int data;
	printf("\nEnter Node to tbe deleted :");
	scanf("%d",&data);
	if(root==NULL){
		printf("\nUnderFlow");
		return NULL;
	}
	while(first!=NULL){
		if(first->info==data){
			temp=first;
			break;
		}
	}
	if(temp!=NULL)
		free(temp);
	return root;
}
void display(NODE *root){
	NODE *first=root;
	if(root==NULL){
		printf("\nEmpty ");
		return;
	}
	printf("\n%d",first->info);
	first=first->link; 
	while(first!=NULL){
		printf(" -> %d",first->info);
		first=first->link;
	}
}
int main(){
	NODE *root=NULL;
	int ch;
	while(1){
		printf("\nMENU\n1.InsertFront\n2.InsertRear\n3.DeleteFront\n4.DeleteRear\n5.DeleteAny\n6.Display\n7.Exit\n");
		printf("\nEnter choice :");
		scanf("%d",&ch);
		switch(ch){
			case 1: root=insertFront(root);
					break;
			case 2:	root=insertRear(root);
					break;
			case 3:	root=deleteFront(root);
					break;
			case 4:	root=deleteRear(root);
					break;
			case 5:	root=deleteAny(root);
					break;
			case 6:	display(root);
					break;
			case 7: 	return 0;
			default: 	printf("\nInvalid choice :");
		}
	}
}
