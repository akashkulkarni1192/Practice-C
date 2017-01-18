#include<stdio.h>
int fib(int n){
	if(n==0 || n==1)
		return n;
	return fib(n-1)+fib(n-2);
}
int dynamicFib(int n){
	int table[20],i;
	table[0]=0;
	table[1]=1;
	for(i=2;i<n;i++)
		table[i]=table[i-1]+table[i-2];
	return table[n-1];
}
int main(){
	int sum,n1=0,n2=1,i,j,n;
	scanf("%d",&n);
	for(i=2;i<n;i++){
		sum=n1+n2;
		n1=n2;
		n2=sum;
	}
	printf("\nNth Fibonacci number : %d\n",sum);
	printf("\nNth Fibonacci number : %d\n",fib(n-1));
	printf("\nNth Fibonacci number : %d\n",dynamicFib(n));
	return 0;
}