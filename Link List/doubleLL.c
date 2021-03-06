#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node *llink;
	struct node *rlink;
}NODE;
NODE* getnode(){
	return (NODE*)malloc(sizeof(NODE));
}
void insertFront(NODE *head,int data){
	NODE *first=head->rlink,*nn=getnode(),*temp;
	nn->info=data;
	if(head->rlink==NULL){
		head->rlink=nn;
		nn->llink=head;
		nn->rlink=NULL;
		return;
	}
	temp=head->rlink;
	nn->llink=head;
	nn->rlink=temp;
	temp->llink=nn;
	head->rlink=nn;
}
void insertRear(NODE *head,int data){
	NODE *first=head->rlink,*nn=getnode(),*temp;
	nn->info=data;
	if(head->rlink==NULL){
		head->rlink=nn;
		nn->llink=head;
		nn->rlink=NULL;
		return;
	}
	while(first->rlink!=NULL)
		first=first->rlink;
	first->rlink=nn;
	nn->llink=first;
	nn->rlink=NULL;
}
void deleteFront(NODE *head){
	NODE *first=head->rlink,*temp;
	if(head->rlink==NULL){
		printf("\nUnderFlow");
		return;
	}
	if(head->rlink->rlink==NULL){
		temp=head->rlink;
		head->rlink=NULL;
	}
	else{
		temp=head->rlink;
		head->rlink=temp->rlink;
		temp->rlink->llink=head;
	}
	free(temp);
}
void deleteRear(NODE *head){
	NODE *first=head->rlink,*temp;
	if(head->rlink==NULL){
		printf("\nUnderFlow");
		return;
	}
	if(head->rlink->rlink==NULL){
		temp=head->rlink;
		head->rlink=NULL;
	}
	else{
		while(first->rlink->rlink!=NULL)
			first=first->rlink;
		temp=first->rlink;
		first->rlink=NULL;
	}
	free(temp);
}
void display(NODE *head){
	NODE *first=head->rlink;
	if(head->rlink==NULL)
		return;
	printf("\n%d",first->info);
	first=first->rlink;
	while(first!=NULL){
		printf(" -> %d",first->info);
		first=first->rlink;
	}
}
int main(){
	NODE *head=getnode();
	int ch,data;
	head->llink=head->rlink=NULL;
	while(1){
		printf("\nMenu\n1.InsertFront\n2.InsertRear\n3.DeleteFront\n4.DeleteRear\n5.Display\n6.Exit\nEnter choice :");
		scanf("%d",&ch);
		switch(ch){
			case 1:	printf("\nEnter info :");
					scanf("%d",&data);
					insertFront(head,data);
					break;
			case 2:	printf("\nEnter info :");
					scanf("%d",&data);
					insertRear(head,data);
					break;
			case 3:	deleteFront(head);
					break;
			case 4:	deleteRear(head);
					break;
			case 5:	display(head);
					break;
			case 6:	return 0;
			default:	printf("\nInvalid choice ");
		}
	}
}
	
