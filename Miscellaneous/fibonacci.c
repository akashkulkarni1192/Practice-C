#include<stdio.h>
int recurseFib(int n){
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	return recurseFib(n-1)+recurseFib(n-2);
}
	
int main(){
	int i,sum,n,n1=0,n2=1;
	printf("\nEnter num :");
	scanf("%d",&n);
	printf("\n->%d\t%d",n1,n2);
	for(i=2;i<=n;i++){
		sum=n1+n2;
		n1=n2;
		n2=sum;
		printf("\t%d",sum);
	}
	printf("\n%d",recurseFib(n));
	printf("\n\n");
	return 0;
}
