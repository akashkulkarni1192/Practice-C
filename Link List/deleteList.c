#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node *link;
}NODE;
NODE* getnode(){
	return (NODE*)malloc(sizeof(NODE));
}
void display(NODE *head){
	NODE *first=head->link;
	if(head->link==NULL)
		return;
	printf("%d",first->info);
	first=first->link;
	while(first!=NULL){
		printf(" -> %d",first->info);
		first=first->link;
	}
}
void insertFront(NODE *head){
	NODE *nn=getnode(),*first=head->link;
	nn->link=NULL;
	printf("\nEnter info : ");
	scanf("%d",&nn->info);
	if(head->link==NULL){
		head->link=nn;
		return;
	}
	nn->link=first;
	head->link=nn;
}
void deleteSubList(NODE *head,int start,int end){
	NODE *first=head->link,*prev,*p,*s,*e;
	if(head->link==NULL || head->info<2)
		return;
	prev=head;
	while(first!=NULL){
		if(first->info==start){
			p=prev;
			s=first;
		}
		if(first->info==end)
			e=first;
		prev=first;
		first=first->link;
	}
	if(e->link==NULL){
		p->link=NULL;
		return;
	}
	s->info=e->link->info;
	s->link=e->link->link;
}
int main(){
	NODE *head=getnode();
	int i=0,start,end;
	head->link=NULL;
	printf("\nEnter no of node :");
	scanf("%d",&head->info);
	while(i++<head->info){
		insertFront(head);
		display(head);
	}
	printf("\nEnter subList End Points : ");
	scanf("%d %d",&start,&end);
	deleteSubList(head,start,end);
	display(head);
	return 0;
}
