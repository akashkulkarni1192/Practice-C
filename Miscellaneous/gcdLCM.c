#include<stdio.h>
int recurseGCD(int m,int n){
	if(m==1 || m==0)
		return n;
	else if(n==1 || n==0)
		return m;
	if(m<n)
		recurseGCD(n,m);
	return recurseGCD(n,m%n);
}
int main(){
	int m,n,i,j;
	printf("\nEnter 2 numbers: ");
	scanf("%d %d",&m,&n);
	for(i=1;i<=m;i++)
		if(m%i==0 && n%i==0)
			j=i;
	printf("\nGCD = %d LCM=%d",j,m*n/j);
	printf("\nRecursion Ans = %d",recurseGCD(m,n));
	return 0;
}
