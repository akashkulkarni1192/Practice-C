#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node *link;
}NODE;
NODE* getnode(){
	return (NODE *)malloc(sizeof(NODE));
}
void display(NODE *head){
	NODE *first=head->link;
	if(head->link==NULL){
		printf("\nEmpty");	
	}
	printf("\n%d",first->info);
	first=first->link;
	while(first!=NULL){
		printf(" -> %d",first->info);
		first=first->link;
	}
	printf("\n");
}
void insert(NODE *head,int data){
	NODE *first=head->link,*nn=getnode();
	nn->info=data;
	nn->link=NULL;
	if(head->link==NULL){
		head->link=nn;
		return;
	}
	while(first->link!=NULL)
		first=first->link;
	first->link=nn;
}
void rotate(NODE *head,int k){
	int i=1;
	NODE *first=head->link,*last=head->link,*temp;
	if(head->link==NULL)
		return;
	if(head->link->link==NULL)
		return;
	while(last->link!=NULL)
		last=last->link;
	while(i<=k){
		temp=first->link;
		last->link=first;
		first->link=NULL;
		last=first;
		first=temp;
		i++;
	}
	head->link=temp;
}
int main(){
	NODE *head=getnode();
	char ch;
	int k;
	head->link=NULL;
	while((ch=getchar())!='\n')
		insert(head,ch-'0');
	display(head);
	printf("\nEnter k(rotations) :");
	scanf("%d",&k);
	rotate(head,k);
	display(head);
	return 0;
}

