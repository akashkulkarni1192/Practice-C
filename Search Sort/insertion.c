#include<stdio.h>
void insertionSort(int a[]){
	int i,j,k,temp;
	for(i=1;i<5;i++){
		j=i-1;
		temp=a[i];
		while(j>=0 && a[j]>temp){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
		printf("\nPass %d: ",5-i);
		for(k=0;k<5;k++)
		printf("%d\t",a[k]);
	}
	
}
int main(){
	int arr[5],i;
	printf("\nenter 5 elements :");
	for(i=0;i<5;i++)
		scanf("%d",&arr[i]);
	//insertion sort now
	insertionSort(arr);
	//display
	printf("\nSorted Array :\t");
	for(i=0;i<5;i++)
		printf("%d\t",arr[i]);
	return 0;
}
