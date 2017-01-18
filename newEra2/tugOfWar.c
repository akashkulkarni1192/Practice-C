//	1 2 3 4 5 6 7 8 9 10
//  1 10 2 9 3


#include<stdio.h>
void merge(int arr[],int low,int high){
	int i=low,k=0,temp[20],l;
	int mid=(low+high)/2;
	int j=mid+1;
	while(i<=mid && j<=high){
		if(arr[i]<arr[j])
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];
	}
	if(i<=mid)
		for(l=i;l<=mid;l++)
			temp[k++]=arr[l];
	else
		for(l=j;l<=high;l++)
			temp[k++]=arr[l];
	for(i=low,k=0;i<=high;i++,k++)
		arr[i]=temp[k];
}
void mergeSort(int arr[],int low,int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		mergeSort(arr,0,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,high);
	}
}
int main(){
	int arr[20],part1[10],part2[10],i,j,n,k=0,sum1,sum2;
	printf("\nEnter size : ");
	scanf("%d",&n);
	printf("\nArray Elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	mergeSort(arr,0,n-1);
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	for(i=0;k<=n/2;i++){
		part1[k++]=arr[i];
		part1[k++]=arr[n-1-i];
	}
	for(k=0;k<=n/2;i++){
		part2[k++]=arr[i];
		part2[k++]=arr[n-1-i];
	}
	printf("\nPart 1 :");
	for(i=0;i<n/2;i++)
		printf("%d\t",part1[i]);
	printf("\nPart 2 :");
	for(i=0;i<n/2;i++)
		printf("%d\t",part2[i]);

	return 0;

}