#include<stdio.h>
#include<string.h>
int main(){
	char string[20],substring[10];
	int i,j,n;
	scanf(" %[^\n]s",string);
	scanf(" %[^\n]s",substring);
	for(i=0;i<string[i];i++){
		for(j=0;substring[j]!='\0' && substring[j]==string[i+j];j++);
		if(j==strlen(substring)){
			printf("\nMatched");
			return 0;
		}
	}
	return 0;
}