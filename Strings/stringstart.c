#include<stdio.h>
int main(){
	char str[20];
	printf("\nEnter String :");
	scanf("%s",str);
	str[0]='Z';
	printf("\nString entered is : %s",str);
	return 0;
}
