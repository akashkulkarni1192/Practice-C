#include<stdio.h>
int main(){
	int i,j,num;
	printf("\nEnter number :");
	scanf("%d",&num);
	for(i=1;i*i<num;i++);
	printf("\n%d << %d << %d \n\n",(i-1)*(i-1),num,i*i);
	return 0;
}
