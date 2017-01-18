/*
	http://www.geeksforgeeks.org/forums/topic/national-instruments-interview-question-for-software-engineerdeveloper-about-linked-lists/
*/

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
	printf("\n");
	while(first!=NULL){
		printf("%d->",first->info);
		first=first->link;
	}
}
void insertRear(NODE *head,int info){
	NODE *first=head->link;
	NODE *nn = getnode();
	nn->info=info; 
	nn->link=NULL;
	if(first==NULL){
		head->link=nn;
		return;
	}
	while(first->link!=NULL)
		first=first->link;
	first->link=nn;
}
void insertFront(NODE *head,int n){
	printf("\ncalling insertFront");
	NODE *first=head->link;
	NODE *nn = getnode();
	nn->info=n; 
	nn->link=NULL;
	if(first==NULL){
		head->link=nn;
		display(head);
		return;
	}
	nn->link=head->link;
	head->link=nn;
	display(head);
}

int add(NODE *first1,NODE *first2,NODE *head3){
	int carry=0,sum;
	printf("\nto add later [ %d + %d ]",first1->info,first2->info);
	if(first1==NULL || first2==NULL)
		return;
	if(first1->link!=NULL && first2->link!=NULL )
		carry=add(first1->link,first2->link,head3);
	// else if(first1->link!=NULL)
	// 	carry=add(first1->link,first2,head3);
	// else if(first2->link!=NULL)
	// 	carry=add(first1,first2->link,head3);

	printf("\nGot carry = %d",carry);
	sum=first1->info + first2->info + carry;
	printf("\n %d + %d , sum = %d ,  carry = %d",first1->info,first2->info,sum,carry);
	insertFront(head3,sum%10);
	return sum/10;

}
int addRest (NODE *head, NODE *first , int leftCarry , NODE *head3){
	int sum=0, carry=0;
	NODE *f= head->link;
	if(f->link!=first)
		carry = addRest(f,first,leftCarry,head3);
	else
		carry = leftCarry;
	sum = f->info + carry;
	insertFront(head3,sum%10);
	return sum/10;
}
int main(){
	NODE *head1=getnode(),*head2=getnode(),*head3=getnode();

	int n1=0,n2=0,n3=0,leftCarry=0;
	NODE *first1 = head1->link=NULL;
	NODE *first2 =head2->link=NULL;
	NODE workingfirst; 
	char ch;
	int i=0,n=0,j,k;
	printf("\nEnter first number");
	while((ch=getchar())!='\n'){
		insertRear(head1,ch-'0');
		n1++;
	}
	printf("\nEnter second number");
	while((ch=getchar())!='\n'){
		insertRear(head2,ch-'0');
		n2++;
	}

	display(head1);
	display(head2);
	first1 = head1->link;
	first2 = head2->link;
	if(n1>n2){
		for(i=0;i<(n1-n2);i++)
			first1=first1->link;
	}
	else if(n1<n2){
		for(i=0;i<(n2-n1);i++)
			first2=first2->link;
	}
	leftCarry = add(first1,first2,head3);
	if(n1>n2)
		addRest(head1,first1,leftCarry,head3);
	else
		addRest(head2,first2,leftCarry,head3);
	printf("Result is : ");
	display(head3);
	return 0;
}