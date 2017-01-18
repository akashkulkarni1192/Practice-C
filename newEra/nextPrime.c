#include<stdio.h>
int main(){
	int num,i;
	scanf("%d",&num);
	while(1){
		num+=2;
		for(i=2;i<num/2 && (num%i!=0);i++);
		if(i==num/2){
			printf("\n%d",num);
			return 0;
		}
	}
}