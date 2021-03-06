#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node *left,*right;
}NODE;
NODE* getnode(int data){
	NODE *nn = (NODE*)malloc(sizeof(NODE));
	nn->info = data;
	nn->left=nn->right=NULL;
	return nn;
}
NODE* insert(NODE *root,int data){
	if(root==NULL)
		return getnode(data);
	else if(data<root->info)
		root->left = insert(root->left,data);
	else
		root->right = insert(root->right,data);
	return root;
}
int max(int x,int y){
	return (x>y)?x:y;
}
int height(NODE *root){
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
}
void levelOrder(NODE *root,int l){
	if(root==NULL)
		return;
	if(l==1){
		printf("%d\t",root->info);
		return ;
	}
	else{
		levelOrder(root->left,l-1);
		levelOrder(root->right,l-1);
	}
}
void display(NODE *root){
	int i,h=height(root);
	for(i=1;i<=h;i++){
		printf("\nLevel %d :\t ",i);
		levelOrder(root,i);
	}
}
int diameter(NODE *root){
	int ld,rd;
	if(root==NULL)
		return 0;
	ld=height(root->left);
	rd=height(root->right);
	return max(ld+rd+1,max(diameter(root->left),diameter(root->right)));
}
int main(){
	NODE *root=NULL;
	int ch,data;
	while(1){
		printf("\nMENU\n1.Insert\n2.Display\n3.Diameter\n4.Exit\nEnter Choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:	printf("\nEnter info : ");
					scanf("%d",&data);	
					root=insert(root,data);
					break;
			case 2:	display(root);
					break;
			case 3:	printf("\nDiameter : %d ",diameter(root));
					break;
			case 4:	return  0;
			default:	printf("\nInvalid Choice ");
		}
	}
}
