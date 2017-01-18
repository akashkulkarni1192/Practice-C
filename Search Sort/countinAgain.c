#include<stdio.h>
int main(){
	int arr[10],freq[10],f[10],i,j,n,min,max,sum=0,output[10];
	printf("\nEnter size :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	min=0;
	max=0;
	for(i=0;i<n;i++){
		if(arr[min]>arr[i])
			min=i;
		if(arr[max]<arr[i])
			max=i;
	}
	printf("\nMin = %d Max = %d ",arr[min],arr[max]);
		
	for(i=0;i<=arr[max]-arr[min];i++)
		freq[i]=0;
	printf("\nFrequencies(Empty) :");
	for(i=0;i<=arr[max]-arr[min];i++)
		printf("\t%d",freq[i]);
	for(i=0;i<=arr[max]-arr[min];i++)
		f[i]=0;
	printf("\nn=%d",n);
	for(i=0;i<n;i++){
		printf("\nfreq[%d]++ for %d at i=%d",arr[i]-arr[min],arr[i],i);
		freq[arr[i]-arr[min]]++;
	}
	printf("\n-");
	printf("\ni=%d",i);
	for(i=0;i<=arr[max]-arr[min];i++)
		printf("\t%d",freq[i]);
	for(i=0;i<=arr[max]-arr[min];i++){
		sum=0;
		for(j=i;j>=0;j--)
			sum=sum+freq[j];
		f[i]=sum;
	}
	printf("\nF :");
	for(i=0;i<=arr[max]-arr[min];i++)
		printf("\n%d",f[i]);
	for(i=0;i<n;i++)
		output[(f[arr[i]-arr[min]]--)-1]=arr[i];
	printf("\nSorted Array :");
	for(i=0;i<n;i++)
		printf("\t%d",output[i]);
	printf("\n\n\n");
	return 0;
}
		
	
