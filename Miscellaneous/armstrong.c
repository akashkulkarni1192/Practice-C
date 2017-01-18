#include<stdio.h>
#include<math.h>
int main(){
	int i,j,k=0,digit,sum=0,n,nums[20];
	printf("\nEnter range : ");
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		digit=i;
		k=sum=0;
		while(digit>0){
			nums[k++]=digit%10;
			digit=digit/10;
		}
		for(j=0;j<k;j++)
			sum+=pow(nums[j],k);
		if(sum==i)
			printf("%d\t",i);
	}
	return 0;
}
