#include<stdio.h>
int main(){
	int arr[10],i,j,n,k=0;
	printf("\nEnter n :");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&j);
		if(j)
			arr[k++]=j;
	}
	for(i=k;i<n;i++)
		arr[i]=0;
	printf("\nArray :");
	for(i=0;i<n;i++)
		printf("\t%d",arr[i]);
	return 0;
}
