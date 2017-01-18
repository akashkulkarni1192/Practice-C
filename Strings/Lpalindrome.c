#include<stdio.h>
int main(){
	char str[20];
	int i,j,n,left,right,l,r,maxlen=0,len;
	printf("\nEnter String :");
	scanf("%s",str);
	for(n=0;str[n];n++);
	for(left=0;left<n;left++)
		for(right=left;right<n;right++){
			printf("\nScan from left=%d to right = %d",left,right);
			for(i=left;i<=right && (str[i]==str[right-(i-left)]);i++);
			printf("\ni=%d right=%d",i-1,right);
			if((i-1)==right){
				printf("\nPalindrome found: ");
				for(j=left;j<=right;j++)
					printf("%c",str[j]);
				len=right-left+1;
				if(maxlen<len){
					maxlen=len;
					l=left;
					r=right;
				}
			}
		}

	printf("\nLongest Palindrome : ");
	for(j=l;j<=r;j++)
		printf("%c",str[j]);
	printf("\n");
	return 0;
}
			
				
