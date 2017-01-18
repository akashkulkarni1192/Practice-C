#include<stdio.h>

void sort(int a[]){
	int i,j,k;
	for(i=0;i<5-1;i++)
		for(j=0;j<5-1-i;j++)
			if(a[j]>a[j+1])
				a[j]=a[j]+a[j+1]-(a[j+1]=a[j]);
}
void binary_search(int a[],int key){
	int min,mid,max,i,j;
	min=0;
	max=5;
	while(min<=max){
		mid=(min+max)/2;
		printf("\na[%d]=%d",mid,a[mid]);
		if(key==a[mid]){
			printf("\nsearch found :");
			return;
		}
		else if(key<a[mid]){
			printf("key<a[m]");
			max=mid-1;
		}
		else{
			printf("key<a[m]");
			min=mid+1;
		}
	}	
	printf("\nSearch not Found ");
}
char* rec_binary_search(int a[],int key,int min,int max){
	int mid= (min+max)/2;
	if (a[mid]==key)
		return "found";
	else if(a[mid]<key)
		return rec_binary_search(a,key,mid+1,max);
	else
		return 	rec_binary_search(a,key,min,mid-1);
	return "notFound";
}
int main(){
	int arr[10],i,j,key,del,k;
	printf("\nEnter 5 elements: ");
	for(i=0;i<5;i++)
		scanf("%d",&arr[i]);
	//input key	
	printf("\nEnter key :");
	scanf("%d",&key);
	//do sort	
	sort(arr);
	printf("Sorted array");
	for(i=0;i<5;i++)
		printf("%d\t",arr[i]);
	//do search 
	binary_search(arr,key);
	printf("\n%s",rec_binary_search(arr,key,0,5-1));
	return 0;
}
