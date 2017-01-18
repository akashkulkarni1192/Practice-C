//	2 5 2 8 5 6 8 8
//  0 1 2 3 4 5 6 7 8
//  0 0 2 0 0 2 1 0 3

#include<stdio.h>
#include<unistd.h>
int main(){
	int arr[10],freq[1000],i,j,n,max,k,item;
	scanf("\nEnter elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
		freq[i]=0;
	for(i=0;i<n;i++)
		freq[arr[i]]++;
	max=freq[arr[0]];
	i=0;
	while(i<n){
		for(;i<n && freq[arr[i]]==0;i++);
		max=freq[arr[i]];
		item=arr[i];
		for(k=i;k<n;k++){
			if(max<freq[arr[k]]){
				max=freq[arr[k]];
				item =arr[k];
			}
		}
		for(k=0;k<max;k++)
			printf("%d\t",item);
		freq[item]=0;
	}
	return 0;
}