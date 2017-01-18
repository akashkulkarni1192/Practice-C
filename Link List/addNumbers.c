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
void display(NODE *h){
	NODE *first=h->link;
	if(h->link==NULL)
		return; 
	while(first!=NULL){
		printf("%d",first->info);
		first=first->link;
	}
}
void recDisplay(NODE *n){
	if(n==NULL)
		return;
	recDisplay(n->link);
	printf("%d",n->info);
}
NODE* add(NODE *h1,NODE *h2){
	int carry=0,digit,sum=0;
	NODE *first1=h1->link,*first2=h2->link,*res=getnode();
	res->link=NULL;
	while(first1!=NULL && first2!=NULL){
		digit=first1->info+first2->info+carry;
		insertFront(res,digit%10);
		carry=digit/10;
		first1=first1->link;
		first2=first2->link;
	}
	while(first1!=NULL){
		digit=first1->info+carry;
		insertFront(res,digit%10);
		carry=digit/10;
		first1=first1->link;
	}
	while(first2!=NULL){
		digit=first2->info+carry;
		insertFront(res,digit%10);
		carry=digit/10;
		first2=first2->link;
	}
	if(carry!=0)
		insertFront(res,carry);
	return res;
}
int main(){
	NODE *head1=getnode(),*head2=getnode(),*head3=getnode();
	head1->link=head2->link=NULL,head3->link=NULL;
	int n1=0,n2=0;
	char ch;
	printf("\nEnter 1st digit : ");
	while((ch=getchar())!='\n'){
		insertFront(head1,ch-'0');
		n1++;
	}
	head1->info=n1;
	printf("\nEnter 2nd digit : ");
	while((ch=getchar())!='\n'){
		insertFront(head2,ch-'0');
		n2++;
	}
	head2->info=n2;
	printf("\n");
	recDisplay(head1->link);
	printf(" + ");
	recDisplay(head2->link);
	printf(" = ");
	head3=add(head1,head2);
	display(head3);
	return 0;
}
