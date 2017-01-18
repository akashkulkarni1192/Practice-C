#include<stdio.h>
int main(){
	int arr[10],output[10],freq[10],freq1[10],i,j,sum=0;
	char c;
	//inputtin
	printf("\nEnter 5 elements :");
	for(i=0;i<5;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<10;i++){
		freq[i]=0;	
	}
	printf("\nFREQ array :\t");
	for(i=0;i<10;i++)
		printf("%d\t",freq[i]);
	for(i=0;i<5;i++)
		freq[arr[i]]++;
	printf("\nfilled FREQ array :\t");
	for(i=0;i<10;i++)
		printf("%d\t",freq[i]);
	/*for(i=0;i<9;i++)
		freq1[i]=-1;*/
	freq1[0]=0;
	for(i=1;i<10;i++){
		freq1[i]=freq1[i-1]+freq[i];
		//printf("\nfreq1[%d] processing",i);
		/*sum=0;
		for(j=i;j>=0;j--)
			sum=sum+freq[j];
		freq1[i]=sum;*/
		//printf("\nFreq1[%d] done",i);
	}
	printf("\nFREQ1 array :\t");
	for(i=0;i<10;i++)
		printf("%d\t",freq1[i]);
	for(i=0;i<10;i++)
		output[i]=-1;
	for(i=0;i<5;i++){
		output[freq1[arr[i]]]=arr[i];
		//output[freq1[i]]=i;
		printf("\n-");
		for(j=0;j<10;j++)
			printf("%d\t",output[j]);
		freq1[arr[i]]--;
	}
	printf("\nOUTPUT array :\t");
	for(i=0;i<10;i++)
		printf("%d\t",output[i]);
	return 0;
}
