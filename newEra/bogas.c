#include<stdio.h>
int main(){
	int arr[20],i,j,n,col,start=0,jump,colPrinted=0,numPrinted=0;
	printf("\nArray Size : ");
	scanf("%d",&n);
	printf("\nArray Elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("\nColumn Size : ");
	scanf("%d",&col);
	jump=col;
	printf("\n");
	i=start++;
	do{
		printf("%d\t",arr[i]);
		i+=jump;
		jump--;
		colPrinted++;
		numPrinted++;
		if(colPrinted==col){
			colPrinted=0;
			printf("\n");
			jump=col;
			i=start++;
		}
	}while(numPrinted<n);
	printf("\n");
	return 0;
}