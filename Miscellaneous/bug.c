#include<stdio.h>
#include<string.h>	
int main(){ 
	char *s= (char*)malloc(sizeof(char));
	scanf("%s",s);
	printf("%s\n",s);	
	return 0;
}
