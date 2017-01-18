//Print all triplets
#include<stdio.h>
#include<math.h>
int main(){
	
	int a[20],n,i,j,trip[3],p,k;
	
	printf("Enter n:\n");
	scanf("%d",&n);
	
	printf("Enter elements: \n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	printf("\nTriplets:\n");
	for(i=0;i<pow(2,n);i++){
		p=0;
		//printf("%d %d \n",n,(int)pow(2,n));
		for(j=0;j<n;j++){
			if(i & 1<<j){
				trip[p++]=a[j];
			}
		}
		if(p==3){
			printf("\n");
			for(k=0;k<p;k++){
				printf("%d	",trip[k]);
			}
		}
	}
	
	return 0;
}