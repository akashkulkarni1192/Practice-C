#include<stdio.h>
int n;
void display(int heap[]){
	int i;
	printf("\nHeap contains :");
	for(i=0;heap[i];i++)
		printf("\t%d",heap[i]);
}
void heapify(int heap[],int parent){
	int bigChild=2*parent+1;
	printf("\n parent = %d",parent);
	if(2*parent+1<n){
		if(2*parent+2<n){
			if(heap[2*parent+1]<heap[2*parent+2])
				bigChild=2*parent+2;
		}
	}else
		return;
	if(heap[parent]>heap[bigChild])
		return;
	heap[parent]=heap[parent]+heap[bigChild]-(heap[bigChild]=heap[parent]);
	display(heap);
	heapify(heap,bigChild);
}
void buildHeap(int heap[]){
	char ch;
	int i;
	printf("\nEnter size : ");
	scanf("%d",&n);
	printf("Enter elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&heap[i]);
	heap[n]='\0';
	display(heap);
	for(i=n/2;i>=0;i--){
		printf("\n i= %d\n",i);
		heapify(heap,i);
	}
}
void heapSort(int heap[]){
	int i;
	for(i=n-1;i>=0;i--){
		heap[0]=heap[0]+heap[i]-(heap[i]=heap[0]);
		n--;
		heapify(heap,0);
	}
}
int main(){
		int ch,heap[10];
		while(1){
			printf("\nMenu \n1:Build Heap\n2.Display Heap\n3.Heap Sort4.\nExit");
			scanf("%d",&ch);
			switch(ch){
				case 1:		buildHeap(heap);
							break;
				case 2:		display(heap);
							break;
				case 3:		heapSort(heap);
							break;
				case 4:		return 0;
				default:	printf("\nInvalid choice");
			}
		}
}
