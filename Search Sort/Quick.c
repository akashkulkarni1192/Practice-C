#include<stdio.h>
int partition(int arr[],int l,int h){
	int pivot=l,i=l+1,j=h;
	while(i<=j){
		while(arr[i]<arr[pivot] && i<=h)
			i++;
		while(arr[pivot]<arr[j] && j>=0)
			j--;
		printf("\nTo be swapped arr[%d] = %d and arr[%d] = %d ",i,arr[i],j,arr[j]);
		if(i<j)
			arr[i]=arr[i]+arr[j]-(arr[j]=arr[i]);
	}
	printf("\nTo be swapped pivot %d and %d ",arr[pivot],arr[j]);
	arr[pivot]=arr[pivot]+arr[j]-(arr[j]=arr[pivot]);
	return j;
}
void qwicksort(int arr[],int low,int high){
	printf("\nAt StackFrame ( %d - %d )",low,high);
	if(low<high){
		int s=partition(arr,low,high);
		qwicksort(arr,low,s-1);
		qwicksort(arr,s+1,high);
	}
}
int main(){
	int arr[10],i,n;
	char ch;
	printf("\nEnter size :");
	scanf("%d",&n);
	printf("\nArray :");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	qwicksort(arr,0,n-1);
	printf("\nSorted array :\t");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
	return 0;
}

