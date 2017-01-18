#include<stdio.h>
void combine(int a[],int l,int m,int h){
	printf("\nUnder Combine :%d -> %d",l,h);
	int i,j,x,temp[10],k=l;
	i=l;
	j=m+1;
	for(x=0;x<10;x++)
		temp[x]=-1;
	while(i<=m && j<=h){
		if(a[i]<a[j]){
			temp[k++]=a[i++];
			printf("\ni temp[%d]=%d",k-1,a[i-1]);
		}
		else{
			temp[k++]=a[j++];
			printf("\nj temp[%d]=%d",k-1,a[j-1]);		
		}
	}
	if(i<=m)
		for(x=i;x<=m;x++){
			//printf("\nX at i=%d",i);
			temp[k++]=a[x];
			printf("\nix temp[%d]=%d",k-1,a[x-1]);
		}
	else if(j<=h)
		for(x=j;x<=h;x++){
			temp[k++]=a[x];
			printf("\njx temp[%d]=%d",k-1,a[x-1]);
		}
	for(x=l;x<=h;x++)
		a[x]=temp[x];
	printf("\nCombined array :\t");
	for(x=0;x<k;x++)
		printf("%d\t",a[x]);		
}
void split(int a[],int low,int high){
	
	if(low<high){
		printf("\nUnder Split :%d -> %d",low,high);	
		int mid=(low+high)/2;
		split(a,low,mid);
		split(a,mid+1,high);
		combine(a,low,mid,high);
	}
}

int main(){
	int arr[5],i;
	printf("\nEnter 5 elements :");
	for(i=0;i<5;i++)
		scanf("%d",&arr[i]);
	//begin mergesorting
	split(arr,0,4);
	//display
	printf("\nSorted Array :\t");
	for(i=0;i<5;i++)
		printf("%d\t",arr[i]);
	return 0;
}
