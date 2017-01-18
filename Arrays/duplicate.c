#include<stdio.h>
#include<stdlib.h>

#include<time.h>

int main(){
	int arr[10],freq[10],i,j,n,k,c,x;
	printf("\nEnter size :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	//removing duplicates
	c=n-1;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			//sleep(1);
			if(arr[j]==arr[i] && arr[j]!=-1){
				//scanf("%d",&x);
				//printf("\nmatched at a[%d] to a[%d] ",i,j);
				//scanf("%d",&x);
				for(k=j;k<n && arr[k]!=-1;k++)
					arr[k]=arr[k+1];
				arr[c--]=-1;
				j--;
				
				//k=j;
				/*while((arr[k]!='\0' || arr[k]!=-1) && k<n)
					arr[k]=arr[k+1];

			1 2 3 2 3 2 4
			1 2 3 3 2 4 -1
			1 2 3 3 4 -1 -1
			1 2 3 4 -1 -1 -1
			
				arr[k*/
				/*for(k=j,c=0;c<n-j-1 && arr[k]!=-1;c++,k++)
					arr[k]=arr[k+1];
				arr[k]=-1;
				i=i-1;*/
			}
		}
		
	}
	printf("\nAfter removing duplicates :");
	for(i=0;arr[i]!=-1;i++)
		printf("\t%d",arr[i]);
	 printf("\n\n\n");
	return 0;
}
	
