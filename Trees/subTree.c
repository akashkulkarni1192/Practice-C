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
int max(int a,int b){
	return (a>b)?a:b;
}
int height(NODE *root){
	if(root==NULL)	
		return 0;
	return 1+max(height(root->left),height(root->right));
}
void display(NODE *root,int level){
	if(root==NULL)
		return;
	else if(level==1)
		printf("\t%d",root->info);
	else{
		display(root->left,level-1);
		display(root->right,level-1);
	}
}
void levelorder(NODE *root){
	int i;
	printf("H=%d",height(root));
	for(i=1;i<=height(root);i++){
		printf("\nLevel %d :",i);
		display(root,i);
	}
}
NODE* inputSubtree(NODE *root){
	char ch;
	printf("\nEnter subtree :");
	scanf("%c",&ch);
	while((ch=getchar())!='\n'){
		printf("ch=%c",ch);
		root=insert(root,ch-'0');
	}
	levelorder(root);	
	return root;
}
int identical(NODE *root,NODE *subroot){
	if(root==NULL && subroot==NULL)
		return 1;
	else if(root==NULL||subroot==NULL)
		return 0;
	else
		return ((root->info==subroot->info) && identical(root->left,subroot->left) && identical(root->right,subroot->right));
	
}
int checkSubtree(NODE *root,NODE *subroot){
	if(subroot==NULL)
		return 1;
	else if(root==NULL)
		return 0;
	else if(identical(root,subroot))
		return 1;
	else 
		return (checkSubtree(root->left,subroot)||checkSubtree(root->right,subroot));
}
int main(){
	NODE *root=NULL,*subroot=NULL;
	int ch,data;
	char s[100]="";
	printf("\n Bool = %d",((1>2)||(4>1)));
	while(1){
		printf("\nMENU\n1.Insert\n2.Display\n3.Subtree\n4.Exit\nEnter choice :");
		scanf("%d",&ch);
		switch(ch){
			case 1:	printf("\nEnter info :");
					scanf("%d",&data);
					root=insert(root,data);
					break;
			case 2:	levelorder(root);
					break;
			case 3:	subroot=inputSubtree(subroot);
					if(checkSubtree(root,subroot))
						printf("\nYes");
					else
						printf("\nNo");
					break;
			case 4:	return 0;
			default:	printf("\nInvalid choice ");
		}
	}
}


