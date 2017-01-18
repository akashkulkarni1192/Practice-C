#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
typedef struct node NODE;
NODE * getnode(){
	NODE *n;
	n=(NODE*)malloc(sizeof(NODE));
	return n;
}
void display(NODE *root){
	NODE *first=root;
	printf("\n%d ",first->info);
	first=first->link;
	while(first!=NULL){
		printf("-> %d",first->info);
		first=first->link;
	}
}
NODE* insert(NODE *root){
	int data;
	NODE *first,*nn=getnode();
	printf("\nEnter info :");
	scanf("%d",&data);
	nn->info=data;
	nn->link=NULL;
	if(root==NULL)
		return nn;
	first=root;
	while(first->link!=NULL)
		first=first->link;
	first->link=nn;
	return root;		
}
NODE* delete(NODE* ptr){
	NODE *temp;
	ptr->info=ptr->link->info;
	temp=ptr->link;
	ptr->link=ptr->link->link;
	free(temp);
}
int main(){
	NODE *root,*first;
	int i;
	printf("\nEnter 5 nodes \n");
	for(i=0;i<5;i++)
		root=insert(root);
	display(root);
	printf("\nPointer to 3rd node is sent (will be deleted)\n");
	delete(root->link->link);
	display(root);
	return 0;
}
