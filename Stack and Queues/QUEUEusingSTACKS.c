#include<stdio.h>
#define SIZE 5
int stack[10],popStack[10];
int top=-1,poptop=-1;
void insert(int data){
	if(top==SIZE-1){
		printf("\nOverFlow");
		return;
	}
	stack[++top]=data;
}
int delete(){
	if(top==-1 && poptop==-1){
		printf("\nUnderFlow");
		return;
	}
	if(poptop!=-1)
		return popStack[poptop--];
	while(top!=-1 && poptop<SIZE)
		popStack[++poptop]=stack[top--];
	return popStack[poptop--];
}
void display(){
	int i;
	if(top==-1 && poptop==-1){
		printf("\nEmpty");
		return;
	}
	printf("\nContainer 2: ");
	for(i=poptop;i>=0;i--)
		printf("\t%d",popStack[i]);
	printf("\nContainer 1: ");
	for(i=0;i<=top;i++)
		printf("\t%d",stack[i]);
}
int main(){
	int data,ch;
	while(1){
		printf("\nMENU\n1.Insert\n2.Delete\n3.Display\n4.Exit");
		scanf("%d",&ch);
		switch(ch){
			case 1:	printf("\nEnter number :");
					scanf("%d",&data);
					insert(data);
					break;
			case 2:	printf("\nDeleted item : %d",delete());
					break;
			case 3:	display();
					break;
			case 4:	return 0;
			default:	printf("\nInvalid Choice ");
		}
	}
}
