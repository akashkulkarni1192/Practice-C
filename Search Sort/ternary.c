#include<stdio.h>
char* ternarySearch(int arr[],int key){
	int i,j,min,max,mid1,mid2;
	min=0;
	max=5;
	mid1=(min+max)/3;
	mid2=2*(min+max)/3;
	while(min<=max){
		mid1=(min+max)/3;
		mid2=2*(min+max)/3;
		if(arr[mid1]==key || arr[mid2]==key)
			return "found";
		else if(key<arr[mid1])
			max=mid1-1;
		else if(key>arr[mid1] && key<arr[mid2]){
			min=mid1+1;
			max=mid2-1;
		}
		else
			min=mid2+1;
	}
	return "not Found";
}
int main(){
	int arr[10],i,key;
	printf("\nEnter 5 elements :");
	for(i=0;i<5;i++)
		scanf("%d",&arr[i]);
	//sorting
	printf("\nEnter key:");
	scanf("%d",&key);
	printf("\nResult : %s",ternarySearch(arr,key));
	return 0;
}
