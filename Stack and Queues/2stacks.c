#include<stdio.h>
int stack[10],top1=-1,top2=10;
void push1(int e){
	if((top1+1)==top2){
		printf("\nOverflow");
		return;
	}
	stack[++top1]=e;
	printf("\n 1 stack[%d]=%d",top1,stack[top1]);	
}
void push2(int e){
	if((top2-1)==top1){
		printf("\nOverflow");
		return ;
	}
	stack[--top2]=e;	
	printf("\n 2 stack[%d]=%d",top2,stack[top2]);
}
int pop1(){
	if(top1==-1){
		printf("\nUnderflow");
		return -1;
	}
	printf("\n1 stack[%d]=%d popped ",top1,stack[top1]);
	return stack[top1--];
}
int pop2(){
	if(top2==10){
		printf("\nUnderflow");
		return -1;
	}
	printf("\n2 stack[%d]=%d popped ",top2,stack[top2]);
	return stack[top2++];
}
void display(){
	int i,j;
	printf("\nStack 1: ");
	for(i=top1;i>=0;i--)
		printf("\t%d",stack[i]);
	printf("\nStack 2: ");
	for(i=top2;i<10;i++)
		printf("\t%d",stack[i]);
}
int main(){
	int i,j,ch,ch1,ch2,e;
	while(1){
		printf("\nMenu\n1.Push\n2.Pop\n3.Display\n4.Exit");
		scanf("%d",&ch);
		switch(ch){
			case 1:	printf("\Enter Element :");
					scanf("%d",&e);
					printf("\nStack no :");
					scanf("%d",&ch1);
					if(ch1==1)
						push1(e);
					else if(ch1==2)
						push2(e);
					else
						printf("\nElement not inserted");
					break;
			case 2:	printf("\nStack no :");
					scanf("%d",&ch1);
					if(ch1==1)
						printf("\nPopped %d ",pop1());
					else if(ch1==2)
						printf("\nPopped %d ",pop2());
					else
						printf("\nElement not inserted");
					break;
			case 3:	display();
					break;
			case 4:	printf("\nEXITED\n");
					return 0;
			default:	printf("\nInvalid choice \n");
		}
	}
}
