#include<stdio.h>
int main(){
	int arr[20],i,j,k,n,diff=-999;
	scanf("%d",&n);
	printf("\nEnter elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if((arr[j]-arr[i])>diff)
				diff=arr[j]-arr[i];
	printf("\nAns = %d \n",diff);
	return 0;
}