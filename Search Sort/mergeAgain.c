#include<stdio.h>
void combine(int arr[],int low,int high){
	int i=low,mid=(low+high)/2,j=mid+1,k=0,x,temp[10];
	while(i<=mid && j<=high){
		if(arr[i]<arr[j])
			temp[k++]=arr[i++];
		if(arr[i]>=arr[j])
			temp[k++]=arr[j++];
	}
	if(i<=mid)
		for(x=i;x<=mid;x++)
			temp[k++]=arr[x];
	if(j<=high)
		for(x=j;x<=high;x++)
			temp[k++]=arr[x];
	for(x=0;x<k;x++)
		arr[low++]=temp[x];
}
void mergesort(int arr[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		combine(arr,low,high);
	}
}
int main(){
	int arr[10],i,j,n;
	printf("\nEnter size :");
	scanf("%d",&n);
	printf("\nArray :");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	mergesort(arr,0,n-1);
	printf("\nSorted Array :");
	for(i=0;i<n;i++)
		printf("\t%d",arr[i]);
	printf("\n\n\n");
	return 0;
}
