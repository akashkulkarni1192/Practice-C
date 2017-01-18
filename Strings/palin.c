#include<stdio.h>
int main(){
	char str[20];
	int i,j,n;
	printf("\nEnter String :");
	scanf("%s",str);
	for(n=0;str[n];n++);
	for(i=0;i<n && (str[i]==str[n-1-i]);i++);
	if(i==n)
		printf("\nPalindrome");
	else
		printf("\nNope");
	return 0;
}

