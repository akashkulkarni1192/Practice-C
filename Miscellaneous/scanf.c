#include<stdio.h>
#include<stdlib.h>
int main(){
	char s[5],s2[5];
	fgets(s,sizeof(s),stdin);
	printf("%s",s);
	scanf("%s",s2);
	printf("\n\n%s",s2);
	return 0;
}
