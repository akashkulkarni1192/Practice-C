#include<stdio.h>
#include<stdlib.h>

#include<time.h>

int main(){
	int arr[10],uniq[10],freq[10],i,j,n,k,c,x;
	printf("\nEnter size :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	//removing duplicates
	for(i=0;i<n;i++)
		uniq[i]=arr[i];
	c=n-1;
	for(i=0;i<n-1;i++){
		
		for(j=i+1;j<n;j++){
			if(uniq[j]==uniq[i] && uniq[j]!=-1){
				for(k=j;k<n && uniq[k]!=-1;k++)
					uniq[k]=uniq[k+1];
				uniq[c--]=-1;
				j--;
			}
		}
		
	}
	for(i=0;uniq[i]!=-1;i++);
	for(j=0;j<i;j++)
		freq[j]=0;
	for(i=0;uniq[i]!=-1;i++){
		for(j=0;j<n;j++){
			if(uniq[i]==arr[j])
				freq[i]++;
		}
	}
	//printing freq
	printf("\nElement\tFreq\n");
	for(i=0;uniq[i]!=-1;i++)
		printf("%d\t%d\n",uniq[i],freq[i]);	
	return 0;
}
	
