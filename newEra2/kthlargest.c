//	1 4 2 9 5 7 3 6 8 
 


#include<stdio.h>
int partition(int arr[],int low,int high){
	int pivot=low,i=low+1,j=high;
	while(i<=j){
		while(arr[pivot]>arr[i] && i<=high)
			i++;
		while(arr[pivot]<arr[j] && j>low)
			j--;
		//printf("\nTo be swapped arr[%d] = %d and arr[%d] = %d ",i,arr[i],j,arr[j]);
		if(i<j)
			arr[i]=arr[i]+arr[j]-(arr[j]=arr[i]);
	}
	//printf("\nTo be swapped pivot %d and %d ",arr[pivot],arr[j]);
	arr[pivot]=arr[pivot]+arr[j]-(arr[j]=arr[pivot]);
	return j;
}
void findKlargest(int arr[],int low,int high,int k,int n){
	int s;
	//printf("\nAt StackFrame ( %d - %d )",low,high);
	if(low<high){
		s=partition(arr,low,high);
		if(s==n-k)
			return;
		else if(s<n-k)
			findKlargest(arr,s+1,high,k,n);
		else
			findKlargest(arr,low,s-1,k,n);
	}

}
int main(){
	int arr[20],i,j,k,n;
	printf("Enter Size : ");
	scanf("\n%d",&n);
	printf("\nArray elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("\nEnter k :");
	scanf("%d",&k);
	for(i=1;i<=k;i++){
		findKlargest(arr,0,n-1,i,n);
		printf("\nElement %d largest: %d\n",n,arr[n-i]);
	}
	return 0;
}