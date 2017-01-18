#include<stdio.h>
#include<string.h>
int main(){
	char str[20],t;
	int i,j,n;
	printf("\nEnter String :");
	scanf("%s",str);
	for(n=0;str[n];n++);
	for(i=0;i<n/2;i++)
		str[i]=str[i]+str[n-1-i]-(str[n-1-i]=str[i]);
	printf("\nReversed String : %s \n",str);
	return 0;
}
