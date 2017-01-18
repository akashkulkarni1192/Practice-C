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
	NODE *cur,*prev,*nn=getnode();
	printf("\nEnter info :");
	scanf("%d",&data);
	nn->info=data;
	nn->link=NULL;
	if(root==NULL)
		return nn;
	cur=root;
	while(cur->link!=NULL)
		cur=cur->link;
	cur->link=nn;
	return root;
		
}

NODE* removeDup(NODE *root){
	NODE *first=root,*cur,*prev,*next;
	if(root==NULL)
		return NULL;
	if(root->link==NULL)
		return root;
	while(first!=NULL){
		prev=first;
		cur=first->link;
		while(cur!=NULL){
			if(cur->info==first->info){
				prev->link=cur->link;
				cur=cur->link;	
			}
			else{
				prev=cur;
				cur=cur->link;
			}
		}
		first=first->link;
	}
	return root;
}	
int main(){
	NODE *root;
	int i,n;
	printf("\nNumber of nodes : ");
	scanf("%d",&n);
	printf("\nEnter %d nodes \n",n);
	for(i=0;i<n;i++){
		root=insert(root);
		display(root);
	}
	root=removeDup(root);
	display(root);
	printf("\n");
	return 0;
}
