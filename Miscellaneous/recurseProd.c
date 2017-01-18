#include<stdio.h>
int func(int digit,int prod){
	if(digit<=0)
		return prod;
	return func(digit/10,prod*(digit%10));
}
int main(){
	int i=976;
	printf("\n\nAns = %d",func(i,1));
	return 0;
}
	
