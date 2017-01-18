#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node *link;
}NODE;
NODE* getnode(){
	return (NODE*)malloc(sizeof(NODE));
}
void insertFront(NODE *h,int data){
	NODE *first=h->link,*nn=getnode();
	nn->info=data;
	if(h->link==NULL){
		h->link=nn;
		nn->link=NULL;
		return;
	}
	nn->link=h->link;
	h->link=nn;
}
void insertRear(NODE *head, int data){
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
int formNumber(NODE *n,int num){
	if(n==NULL)
		return 0;
	num=formNumber(n->link,num);
	num = num*10+n->info;
	return num;
}
void recDisplay(NODE *n){
	if(n==NULL)
		return;
	recDisplay(n->link);
	printf("%d",n->info);
}
void multiply(NODE *h2,NODE *h1,int n){
	NODE *first=h1->link;
	int carry=0,d;
	if(h1->link==NULL)
		return;
	while(first!=NULL){
		d=n*first->info+carry;
		insertRear(h2,d%10);
		carry=d/10;
		first=first->link;
	}
	if(carry!=0){
		while(carry>0){
			insertRear(h2,carry%10);
			carry=carry/10;
		}
	}
}
int main(){
	NODE *head1=getnode(),*first,*head2=getnode();
	head2->link=NULL;
	head1->link=NULL;
	char ch;
	int i,num=0,prod=1,digit,n;
	printf("\nEnter num : ");
	while((ch=getchar())!='\n'){
		insertFront(head1,ch-'0');
	}
	first=head1->link;
	num=formNumber(head1->link,0);
	printf("\nNUmber Fromed");
	for(i=num-1;i>1;i--){
		multiply(head2,head1,i);
		head1->link=head2->link;
		head2->link=NULL;
	}
	printf("\n %d ! = ",num);
	recDisplay(head1->link);
	printf("\n\n\n");
	return 0;
}
