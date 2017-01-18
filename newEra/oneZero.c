#include<stdio.h>
int main(){
	int n,i=2,j,num;
	scanf("%d",&n);
	num=n;
	do{
		while(num>0){
			if(num%10!=0 && num%10!=1)
				break;
			num/=10;
		}
		if(num==0){
			printf("\n%d",n*i);
			return 0;
		}
		num=n*(++i);
	}while(1);
}