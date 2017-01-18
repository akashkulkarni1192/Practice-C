//	This is a book
//  
//  3
//  s is a bookThi

#include<stdio.h>
#include<string.h>
void leftrotate(char str[],int k){
	int n=strlen(str),i,j=0,l=0;
	char temp[k];
	for(i=0;i<k;i++)
		temp[j++]=str[i];
	for(i=k;i<n;i++){
		str[i-k]=str[i];
		printf("\n- %s",str);
	}
	for(i=n-k,l=0;i<n && l<k;i++,l++)
		str[i]=temp[l];
}
void rightrotate(char str[],int k){
	int n=strlen(str),i,j=0,l=0;
	char temp[k];
	for(i=n-k;i<n;i++)
		temp[j++]=str[i];
	for(i=n-k-1;i>=0;i--)
		str[i+k]=str[i];
	for(i=0;i<k ;i++)
		str[i]=temp[i];
}
int main(){
	char str[20];
	int i,j,ch,k;
	scanf(" %[^\n]s",str);
	printf("\nRotate By : ");
	scanf("%d",&k);
	//leftrotate(str,k);
	rightrotate(str,k);
	printf("\nString rotated : %s",str);
	return 0;
}