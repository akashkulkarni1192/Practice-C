#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node *left;
	struct node *right;
}NODE;
NODE* newnode(int data){
	NODE *n=(NODE*)malloc(sizeof(NODE));
	n->left=n->right=NULL;
	n->info=data;
	return n;
}
NODE* insert(NODE *root,int data){
	if(root==NULL)
		root=newnode(data);
	else if(data<root->info)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	return root;
}
void inorder(NODE *root){
	if(root==NULL)
		return;
	inorder(root->left);
	printf("\t%d",root->info);
	inorder(root->right);
}
int no_of_nodes(NODE *root,int s){
	if(root==NULL)
		return s;
	else if(root->left==NULL && root->right==NULL)
		s=s+1;
	else{
		s=no_of_nodes(root->left,s);
		s=no_of_nodes(root->right,s);
	}
	return s;
}
int leaves(NODE *root){
	if(root==NULL)
		return 0;
	else if(root->left==NULL && root->right==NULL)
		return 1;
	return leaves(root->left)+leaves(root->right);
}
int max(int a,int b){
	return (a>b)?a:b;
}
int height(NODE *root){
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
}
void levelnodes(NODE *root,int l){
	if(root==NULL)
		return;
	else if(l==1)
		printf("\t%d",root->info);
	else{
		levelnodes(root->left,l-1);
		levelnodes(root->right,l-1);
	}
}
void levelorder(NODE *root){
	int i;
	for(i=1;i<=height(root);i++){
		levelnodes(root,i);
	}
}
void display(NODE *root){
	printf("\nInorder :");
	inorder(root);
	printf("\nLevel order :");
	levelorder(root);
}
int main(){
	NODE *root=NULL;
	int ch,data;
	while(1){
		printf("\nMENU\n1.Insert\n2.Display\n3.No of nodes\n4.Exit\nEnter choice :");
		scanf("%d",&ch);
		switch(ch){
			case 1:	printf("\nEnter info :");
					scanf("%d",&data);
					root=insert(root,data);
					break;
			case 2:	display(root);
					break;
			case 3:	printf("\nNo of leaves : %d\nLeaves =%d",no_of_nodes(root,0),leaves(root));
					break;
			case 4:	return 0;
			default:	printf("\nInvalid choice ");
		}
	}
}

