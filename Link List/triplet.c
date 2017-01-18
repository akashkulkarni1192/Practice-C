/*
	1	2	3	4
	2	3	4	4
	5	4	3	1
	
	
	
	sum=6

*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node *link;
}NODE;
NODE* getnode(){
	NODE *nn=(NODE*)malloc(sizeof(NODE));
	return nn;
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
	printf("\n");
	
}
void insert(NODE *head){
	NODE *first=head->link,*nn=getnode();
	printf("\nEnter info : ");
	scanf("%d",&nn->info);
	nn->link=NULL;
	if(head->link==NULL){
		head->link=nn;
		return;	
	}
	while(first->link!=NULL)
		first=first->link;
	first->link=nn;
}
void findTriplet(NODE *head1,NODE *head2,NODE *head3,int sum){
	display(head1);
	display(head2);
	display(head3);
	//int trip[head1->info*head2->info*head3->info];
	NODE *f1=head1->link,*f2=head2->link,*f3=head3->link,*g1=f1,*g2=f2,*g3=f3;
	while(f1!=NULL){
		f2=g2;
		while(f2!=NULL){
			f3=g3;
			while(f3!=NULL){
				if(f1->info+f2->info+f3->info==sum)
					printf("\n[ %d %d %d]",f1->info,f2->info,f3->info);
				f3=f3->link;
			}
			f2=f2->link;
		}
		f1=f1->link;
	}
}
void findTripletSmart(NODE *head1,NODE *head2,NODE *head3,int sum){
	NODE *f1=head1->link,*f2=head2->link,*f3=head3->link;
	display(head1);
	display(head2);
	display(head3);
	while(f1!=NULL){
		f2=head2->link;
		f3=head3->link;
		while(f2!=NULL && f3!=NULL){
			if(f1->info+f2->info+f3->info==sum){
					printf("\n[ %d %d %d]",f1->info,f2->info,f3->info);
					f3=f3->link;
			}
			else if(f1->info+f2->info+f3->info>sum)
				f3=f3->link;
			else
				f2=f2->link;
		}
		f1=f1->link;
	}

}
int main(){
	NODE *head1=getnode(),*head2=getnode(),*head3=getnode();
	int i,sum;
	printf("\nEnter no of node(List 1) : ");
	scanf("%d",&head1->info);
	for(i=0;i<head1->info;i++){
		insert(head1);
		display(head1);
	}
	printf("\nEnter no of node(List 2) : ");
	scanf("%d",&head2->info);
	for(i=0;i<head2->info;i++){
		insert(head2);
		display(head2);
	}
	printf("\nEnter no of node(List 3) : ");
	scanf("%d",&head3->info);
	for(i=0;i<head3->info;i++){
		insert(head3);
		display(head3);
	}
	printf("\nEnter sum : ");
	scanf("%d",&sum);
	//findTriplet(head1,head2,head3,sum);
	findTripletSmart(head1,head2,head3,sum);
	return 0;
}
	
