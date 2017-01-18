#include<stdio.h>
int main(){
	int n[10],num,i,j,len=0;
	char ch;
	printf("\nEnter num :");
	while((ch=getchar())!='\n')
		n[len++]=ch-'0';
	for(i=0;n[i]==n[len-1-i];i++);
	if(i==len)
		printf("\nPalindrome Number \n\n");
	else
		printf("\nNot Palindrome Number \n\n");
	return 0;
}
