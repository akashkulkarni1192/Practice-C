#include<stdio.h>
void compute2ndpart(int subs[50][50],int s){
	int i,j,dif,min,max,maxdif=0,set;
	for(i=0;i<s;i++){
		min=99;
		max=-99;
		for(j=0;subs[i][j];j++){
			if(min>subs[i][j])
				min=subs[i][j];
			if(max<subs[i][j])
				max=subs[i][j];
		}
		dif=max-min;
		if(maxdif<dif){
			maxdif=dif;
			set=i;
		}
	}

	printf("\nMax difference set is :\t");
	for(j=0;subs[set][j];j++)
		printf("%d\t",subs[set][j]);			

}
void findSubset(int arr[],int n){
	int i,j,c,k=0,x,s,subs[50][50];
	s=1;
	s=s<<n;
	for(i=0;i<s;i++){
		k=i;
		printf("\npass of i=%d",i);
		for(j=i,c=0,x=0;c<n;c++,j=j>>1){
			if((j&1)){
				printf("\t%d",arr[c]);
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
	compute2ndpart(subs,s);
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
