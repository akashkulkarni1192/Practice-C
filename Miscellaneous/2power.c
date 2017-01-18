#include<stdio.h>
int main(){
	int num,i,j,n=1;
	printf("\nEnter number :");
	scanf("%d",&num);
	while(n<num)
		n*=2;
	printf("\n%d < %d < %d ",n/2,num,n);
	return 0;
} 
