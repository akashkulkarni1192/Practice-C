#include<stdio.h>
int main(){
	int arr[10],tempap[10],ap[10],dif,d,i,len,j,n,maxlen=0;
	printf("\nEnter size :");
	scanf("%d",&n);
	printf("\nEnter %d elements :",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	//findin ap
	
	dif=arr[1]-arr[0];
	tempap[0]=arr[0];
	tempap[1]=arr[1];
	
	len=2;
	for(i=2;i<n;i++){
		printf("\n i =%d",i);
		d = arr[i]-arr[i-1];
		printf("\n d=%d",d);
		if(d==dif){
			printf("\nstore tempap[%d]=%d",len,arr[i]);
			tempap[len++]=arr[i];
			
		}
		else{
			if(len>maxlen){
				printf("\nnew series got :");
				for(j=0;j<len;j++){
					ap[j]=tempap[j];
					//printf("\t%d",ap[j]);
				}
				
				maxlen=len;
			}
			tempap[0]=arr[i-1];
			tempap[1]=arr[i];			
			len=2;
			dif=d;
				
		}
	}
	printf("\nLongest AP series :\t");
	for(i=0;i<maxlen;i++)
		printf("%d\t",ap[i]);
	return 0;
}
