#include<stdio.h>
//#include<math.h>
void computeSubsetSum(int subs[50][50],int s){
	int i,j,set[10],sum,reqsum,k=0;	
	printf("\nEnter required Sum :");
	scanf("%d",&reqsum);
	for(i=0;i<s;i++){
		sum=0;
		for(j=0;subs[i][j];j++)
			sum+=subs[i][j];
		//printf("\nSum :%d",sum);
		if(reqsum==sum){
			//maxsum=sum;
			//printf("storing subset %d",i);
			set[k++]=i;
		}
	}

	
	printf("\nSubset with Sum=%d are :\n",reqsum);
	for(i=0;set[i];i++){
		printf("\n[");
		for(j=0;subs[set[i]][j];j++)
			printf(" %d",subs[set[i]][j]);
		printf(" ]");
	}

}
void findSubset(int arr[],int n){
	int i,j,c,k=0,x,s,subs[50][50];
	s=1;
	s=s<<n;
	for(i=0;i<s;i++){
		k=i;
		//printf("\npass of i=%d",i);
		for(j=i,c=0,x=0;c<n;c++,j=j>>1){
			if((j&1)){
				//printf("\t%d",arr[c]);
				subs[k][x++]=arr[c];
			}	
		}
	}


	//printing subsets
	printf("\nSubsets : ");
	for(i=0;i<s;i++){
		printf("\n[");
		for(j=0;subs[i][j];j++)
			printf("  %d",subs[i][j]);
		printf(" ]");
	}
	computeSubsetSum(subs,s);

}
int main(){
	int arr[5],i,j,n;
	printf("\nEnter length :");
	scanf("%d",&n);
	printf("\nEnter %d elements :",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	findSubset(arr,n);
	return 0;
}
