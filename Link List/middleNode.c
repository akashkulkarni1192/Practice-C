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
NODE* insert(NODE *root){
	NODE *first=root,*n=getnode();
	printf("\nEnter info :");
	scanf("%d",&n->info);
	n->link=NULL;
	if(root==NULL)
		return n;
	while(first->link!=NULL)
		first=first->link;
	first->link=n;
	return root;
}
void display(NODE *root){
	NODE *first=root;
	if(root==NULL){
		printf("\nEmpty");
		return;
	}
	printf("\n%d",first->info);
	first=first->link;
	while(first!=NULL){
		printf(" -> %d",first->info);
		first=first->link;
	}
}
NODE* delete(NODE *root){
	NODE *cur,*prev=NULL,*temp=NULL;
	int data;
	if(root==NULL){
		printf("\nUnderFlow");
		return NULL;
	}
	printf("\nEnter node :");
	scanf("%d",&data);
	if(root->info==data){
		temp=root;
		root=root->link;
		free(temp);
		return root;
	}
	prev=root;
	cur=root->link;
	while(cur!=NULL){
		if(cur->info==data){
			temp=cur;
			break;
		}
		prev=cur;
		cur=cur->link;
	}
	if(temp!=NULL){
		prev->link=cur->link;
		free(cur);	
	}
	return root;
}
void middle(NODE *root){
	NODE *first=root;
	int n=0,i=0;
	while(first!=NULL){
		n++;
		first=first->link;
	}
	first=root;
	while(first!=NULL){
		if(++i == n/2+1){
			printf("\nMiddle Node = %d",first->info);
			break;	
		}
		first=first->link;
	}	
}
int main(){
	NODE *root;
	int ch;
	while(1){
		printf("\n1.Insert\n2.Find Middle\n3.Delete\n4.Display\n5.Exit\nEnter choice :");
		scanf("%d",&ch);
		switch(ch){
			case 1:	root=insert(root);
					break;
			case 2:	middle(root);
					break;
			case 3:	root=delete(root);
					break;
			case 4:	display(root);
					break;
			case 5:	return 0;
			default:	printf("\nInvalid choice ");
		}
	}
}
