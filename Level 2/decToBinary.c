#include<stdio.h>
void decToBin(int n){
	int i;
	for(i=8;i--;putchar((n&(1<<i))?'1':'0'));
}
int main(){
	int n;
	printf("\nEnter n : ");
	scanf("%d",&n);
	decToBin(n);
	return 0;
}
