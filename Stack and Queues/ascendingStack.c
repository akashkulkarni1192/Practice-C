#include<stdio.h>
typedef struct stack{
	int top;
	int arr[5];
}STACK;
void push(STACK *st,int data){
	if(st->top==4){
		printf("\nOverflow");
		return;
	}
	st->arr[++st->top]=data;
}
int pop(STACK *st){
	if(st->top==-1){
		printf("\nUnderflow ");
		return;
	}
	return st->arr[st->top--];
}
void display(STACK *st){
	int i;
	if(st->top==-1){
		printf("\nEmpty");
		return;
	}
	printf("\nStack Contents :");
	for(i=0;i<=st->top;i++)
		printf("\tStack[%d]=%d",i,st->arr[i]);
}
void sort(STACK *st1,STACK *st2){
	int data;
	while(st1->top!=-1){
		data=pop(st1);
		if(st2->top==-1){
			push(st2,data);
			continue;
		}
		while(data<st2->arr[st2->top] && st2->top!=-1)
			push(st1,pop(st2));
		push(st2,data);	
	}
}		
int main(){
	STACK stack1,stack2;
	stack1.top=stack2.top=-1;
	int data,ch;
	while(1){
		printf("\nMenu\n1.Push\n2.Pop\n3.Display\n4.Sort\n5.Exit\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:	printf("\nEnter element : ");
					scanf("%d",&data);
					push(&stack1,data);
					break;
			case 2:	printf("\nDeleted Item : %d",pop(&stack1));
					break;
			case 3:	display(&stack1);
					break;
			case 4:	sort(&stack1,&stack2);
					stack1=stack2;
					break;
			case 5:	return 0;
			default:	printf("\nInvalid Choice ");
		}
	}
}
