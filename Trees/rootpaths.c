#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int info;
	struct node *left,*right;
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
	else if(root->info>data)
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
void pathleaf(NODE* root,char s[]){
	char ch[10];
	if(root==NULL)
		return;
	strcpy(ch,s);
	sprintf(ch,"%s%d\t",s,root->info);
	printf("\n%d : %s",root->info,ch);
	pathleaf(root->left,ch);
	pathleaf(root->right,ch);
}
int main(){
	NODE *root=NULL;
	int ch,data;
	char s[100]="";
	while(1){
		printf("\nMENU\n1.Insert\n2.Display\n3.Paths\n4.Exit\nEnter choice :");
		scanf("%d",&ch);
		switch(ch){
			case 1:	printf("\nEnter info :");
					scanf("%d",&data);
					root=insert(root,data);
					break;
			case 2:	display(root);
					break;
			case 3:	pathleaf(root,s);
					break;
			case 4:	return 0;
			default:	printf("\nInvalid choice ");
		}
	}
}
