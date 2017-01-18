#include<stdio.h>
int main(){
	int n,i,j,digit;
	for(i=1;i<=100;i++){
		n=i;
		while(n>0){
			if(n%10==7)
				printf("%d\t",i);
			n/=10;
		}
	}
	printf("\n\n");
	return 0;
}
