#include<stdio.h>
#include<stdlib.h>
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
	else if(data<root->info)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	return root;
}
void display(NODE *root){
	if(root==NULL)
		return;
	display(root->left);
	printf("\t%d",root->info);
	display(root->right);
}
void path(NODE *root,int sum,int arr[],int level){
	int i,summ=0;
	if(root==NULL)
		return;
	else{
		arr[level]=root->info;
		for(i=0;i<=level;i++)
			summ+=arr[i];
		if(summ==sum)
			for(i=0;i<=level;i++)
				printf("\t%d",arr[i]);
		path(root->left,sum,arr,level+1);
		path(root->right,sum,arr,level+1);
	}
}
int main(){
	NODE *root=NULL;
	int ch,data,arr[100];
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
			case 3:	printf("\nEnter sum : ");
					scanf("%d",&data);
					path(root,data,arr,0);
					break;
			case 4:	return 0;
			default:	printf("\nInvalid choice ");
		}
	}
}
