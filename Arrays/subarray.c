#include<stdio.h>
int main(){
	int arr[5],i,j,left,right,sum=0,maxsum=0,l,r;
	for(i=0;i<5;i++)
		scanf("%d",&arr[i]);
	for(left=0;left<5-1;left++)
		for(right=left;right<5;right++){
			sum=0;
			for(i=left;i<=right;i++){
				sum+=arr[i];
			}
			if(maxsum<sum){
				l=left;
				r=right;
				maxsum=sum;
			}
		}

	printf("\nResult:");
	for(i=l;i<=r;i++){
		printf("\t%d",arr[i]);
	}
	printf("\nSum : %d",maxsum);
	return 0;	
}
