#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
	int front,rear;
	int arr[5];
}QUEUE;
QUEUE Q;
void insert(int data){
	if((Q.rear+1)%5==Q.front){
		printf("\nOverflow");
		return;
	}
	if(Q.rear==-1)
		Q.front=Q.rear=0;
	else
		Q.rear=(Q.rear+1)%5;
	Q.arr[Q.rear]=data;
}
int delete(){
	int data;
	if(Q.front==-1){
		printf("\nUnderFlow");
		return -1;
	}
	data=Q.arr[Q.front];
	if(Q.front==Q.rear)
		Q.front=Q.rear=-1;
	else
		Q.front=(Q.front+1)%5;
	return data;
}
int pop(){
	int f=Q.rear,data;
	while(Q.front!=f)
		insert(delete());
	return delete();
}
void display(){
	int i;
	for(i=Q.front;i!=Q.rear;i=(i+1)%5)
		printf("\tQueue[%d]=%d",i,Q.arr[i]);
	printf("\tQueue[%d]=%d",Q.rear,Q.arr[Q.rear]);
}
int main(){
	int ch,data;
	Q.front=-1;
	Q.rear=-1;
	while(1){
		printf("\nMENU\n1.Push\n2.Pop\n3.Display\n4.Exit");
		scanf("%d",&ch);
		switch(ch){
			case 1:	printf("\nEnter info : ");
					scanf("%d",&data);
					insert(data);
					break;
			case 2 :	printf("\nDeleted Item : %d",pop());
					break;
			case 3:	printf("\nStack Contents : ");
					display();
					break;
			case 4:	return 0;
			default:	printf("\nInvalid Choice ");
		}
	}
}
