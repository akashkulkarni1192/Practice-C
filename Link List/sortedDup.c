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
	else if(nn->info<root->info){
		nn->link=root;
		return nn;
	}
	prev=root;
	cur=root->link;
	while(cur!=NULL && nn->info>cur->info){
		prev=cur;
		cur=cur->link;
	}
	nn->link=cur;
	prev->link=nn;
	return root;
		
}
NODE* removeDup(NODE *root){
	NODE *first=root,*second,*temp;
	if(root==NULL){
		printf("\nList Empty");
		return NULL;
	}
	if(root->link==NULL){
		printf("\nList has only One Node");
		return root;
	}
	second=root->link;
	while(second!=NULL){
		printf("\n%d %d",first->info,second->info);
		if(second->info==first->info){
			temp=second;
			first->link=second->link;
			second=second->link;
			free(temp);
		}
		else{
			first=second;
			second=second->link;
		}
	
	}
	return root;
}
int main(){
	NODE *root;
	int i;
	printf("\nEnter 5 nodes \n");
	for(i=0;i<5;i++){
		root=insert(root);
		display(root);
	}
	root=removeDup(root);
	display(root);
	printf("\n");
	return 0;
}

