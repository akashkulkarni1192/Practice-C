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
NODE* reverse(NODE *prev,NODE *cur){
	NODE *first;
	if(cur->link==NULL){
		cur->link=prev;
		return cur;
	}
	first=reverse(cur,cur->link);
	cur->link=prev;
	return first;
}
void checkPalindrome(NODE *head){
	NODE *first=head->link,*middle;
	int n=0,i=0;
	if(head->link==NULL)
		return;
	while(first!=NULL){
		n++;
		first=first->link;
	}
	first=head->link;
	while(first!=NULL){
		i++;
		if(i+1==n/2){
			middle=first->link;
			break;
		}
		first=first->link;
	}
	if(n%2==0){
		first=first->link;
		middle=middle->link;
	}
	if(n%2!=0){
		first=first->link;
		middle=middle->link->link;
	}
	first->link=NULL;
	middle=reverse(NULL,middle);
	first=head->link;
	while(first!=NULL && middle!=NULL && first->info==middle->info){
		first=first->link;
		middle=middle->link;
	}
	if(first==middle && first==NULL)
		printf("\nPalindrome ");
	else
		printf("\nNot a palindrome");			
}
int main(){
	NODE *head=getnode();
	char ch;
	head->link=NULL;
	while((ch=getchar())!='\n')
		insert(head,ch-'0');
	display(head);
	checkPalindrome(head);
	return 0;
}
	
	
