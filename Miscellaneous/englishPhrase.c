#include<stdio.h>
char *one[] = {"one","two","three","four","five","six","seven","eight","nine"},ch;
char *ten[] = {"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
char *eleven[] = {"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
void print2(int num[],int n){
	(num[n+1]==0)
		?printf("%s ",*(ten+num[n]-1))
		:(num[n]==1)
			?printf("%s ",*(eleven+num[n]*10+num[n+1]-11))
			:printf("%s %s ",*(ten+num[n]-1),*(one+num[n+1]-1));
}
void print3(int num[],int n){
	printf("%s hundred ",*(one+num[n]-1));
	print2(num,n+1);
}
void print4(int num[],int n){
	printf("%s thousand ",*(one+num[n]-1));
	print3(num,n+1);
}
void print5(int num[],int n){
	print2(num,n);
	printf(" thousand ");
	print3(num,n+2);
}
void print6(int num[],int n){
	printf("\n%s lakh ",*(one+num[0]-1));
	print5(num,n+1);
}
int main(){
	int num[6],n=0;
	printf("\nEnter number \n");
	while((ch=getchar())!='\n')
		num[n++]=ch-'0';
	num[n]='\0';
	if(n==1)
		printf("\n%s\n",*(one+num[0]-1));
	else if(n==2)
		print2(num,0);
	else if(n==3)
		print3(num,0);
	else if(n==4)
		print4(num,0);
	else if(n==5)
		print5(num,0);
	else if(n==6)
		print6(num,0);
	return 0;
}

