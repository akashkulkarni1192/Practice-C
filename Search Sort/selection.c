#include<stdio.h>
void selectionSort(int a[]){
	int min,temp,i,j,pos;
	for(i=0;i<5-1;i++){
		min=a[i+1];
		for(j=i+1;j<5;j++){
			if(a[j]<min){
				min=a[j];
				pos=j;
			}
		}
		a[i]=a[i]+a[pos]-(a[pos]=a[i]);
	}
}
int main(){
	int arr[5],min,i,j,temp;
	printf("\nEnter 5 elements :");
	for(i=0;i<5;i++)
		scanf("%d",&arr[i]);
	//sorting starts

	selectionSort(arr);
	printf("\nSorted Array :");
	for(i=0;i<5;i++)
		printf("%d",arr[i]);
	return 0;
}
