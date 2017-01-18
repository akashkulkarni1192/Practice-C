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
int max(int a,int b){
	return (a>b)?a:b;
}
int getHeight(NODE *root){
	if(root==NULL)
		return 0;
	return 1+max(getHeight(root->left),getHeight(root->right));
}
void width(NODE *root,int arr[],int level,int l){
	if(root==NULL)
		return ;
	else if(level==1)
		arr[l]++;
	else{
		width(root->left,arr,level-1,l);
		width(root->right,arr,level-1,l);
	}
}
int maxwidth(NODE *root){
	int arr[10],i,height=getHeight(root),max=-1;
	for(i=1;i<=height;i++)
		arr[i]=0;
	for(i=1;i<=height;i++){
		width(root,arr,i,i);
		printf("\n Level %d : %dnodes",i,arr[i]);
		if(max<arr[i])
			max=arr[i];
	}	
	return max;
}
int main(){
	NODE *root=NULL;
	int ch,data,arr[100],height;
	while(1){
		printf("\nMENU\n1.Insert\n2.Display\n3.Max Width\n4.Exit\nEnter choice :");
		scanf("%d",&ch);
		switch(ch){
			case 1:	printf("\nEnter info :");
					scanf("%d",&data);
					root=insert(root,data);
					break;
			case 2:	display(root);
					break;
			case 3:	printf("\nMax Width : %d",maxwidth(root));
					break;
			case 4:	return 0;
			default:	printf("\nInvalid choice ");
		}
	}
}
