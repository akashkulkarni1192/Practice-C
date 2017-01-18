#include<stdio.h>
int main(){
	int x = 5,*p=&x,y;
	char ch='a',*q=&ch;
	char s[100];
	printf("\n\n%d stored at %p location\n\n ",x,&x);
	printf("\nSize of int ptr : %lu",sizeof(p));
	printf("\nSize of char ptr : %lu",sizeof(q));	



	//printf("\nEnter 1 char : ");
	//scanf("%1c",&ch);
	printf("\n%c",ch);
	printf("\n\ntakes 3 chars :");

	fflush(stdin);
	scanf("%3s",s);
	printf("\n%s\n\n",s);


	scanf("%2d%3d",&x,&y);
	printf("\nx=%d \ny=%d\n",x,y);
	return 0;
} 
