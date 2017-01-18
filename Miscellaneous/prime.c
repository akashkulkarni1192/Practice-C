#include<stdio.h>
#include<stdlib.h> 
int main(){
	int i,j,n;
	printf("\nEnter num : ");
	scanf("%d",&n);
	for(i=2;i<n/2;i++)
		if(n%i==0){
			printf("\nNot prime\n\n");
			exit(0);
		}
	printf("\nPrime\n\n");
	return 0;
}
	
