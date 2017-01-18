#include<stdio.h>
typedef struct queue{
	int front,rear;
	int arr[5];
}QUEUE;
QUEUE Q;
void insert(int data){
	if((Q.rear+1)%5==Q.front){
		printf("\nOverFlow");
		return;
	}
	if(Q.rear==-1)
		Q.front=Q.rear=0;
	else
		Q.rear=(Q.rear+1)%5;
	Q.arr[Q.rear]=data;
}
int delete(){
	int del;
	if(Q.front==-1){
		printf("\nUnderflow");
		return -1;
	}
	del=Q.arr[Q.front];
	if(Q.front==Q.rear)
		Q.front=Q.rear=-1;
	else
		Q.front=(Q.front+1)%5;
	return del;
}
void display(){
	int i;
	if(Q.rear==-1){
		printf("\nQueue Empty");
		return;
	}
	printf("\nQueue Contents :");
	for(i=Q.front;i!=Q.rear;i=(i+1)%5)
		printf("\tQueue[%d]=%d",i,Q.arr[i]);
	printf("\tQueue[%d]=%d\n",Q.rear,Q.arr[Q.rear]);
}
int main(){
	int ch,data;
	Q.front=-1;
	Q.rear=-1;
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
