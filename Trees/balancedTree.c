#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
void display(NODE *root){
	printf("\nInorder :");
	inorder(root);
}
int max(int a,int b){
	return (a>b)?a:b;
}
int depth(NODE *root){
	if(root==NULL)
		return 0;
	return 1+ max(depth(root->left),depth(root->right));
}
int checkBalance(NODE *root){
	if(root==NULL)
		return 1;
	return (checkBalance(root->left)&&checkBalance(root->right)&&abs(depth(root->left)-depth(root->right))<=1)?1:0;
}
int main(){
	NODE *root=NULL;
	int ch,data;
	while(1){
		printf("\nMENU\n1.Insert\n2.Display\n3.Balanced Yes/No ?\n4.Exit\nEnter choice :");
		scanf("%d",&ch);
		switch(ch){
			case 1:	printf("\nEnter info :");
					scanf("%d",&data);
					root=insert(root,data);
					break;
			case 2:	display(root);
					break;
			case 3:	if(checkBalance(root))
						printf("\nbalanced ");
					else
						printf("\nNot Balanced");
					break;
			case 4:	return 0;
			default:	printf("\nInvalid choice ");
		}
	}
}

