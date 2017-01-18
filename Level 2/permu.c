#include<stdio.h>
void generate(char input[],int n){
	int c;
	if(n==0){
		printf("\n%s",input);
		return ;
	}
	for(c=0;c<=n;c++){
		printf("\n\nSTACK FRAME (%d)",n);
		printf("\n c= %d at n=%d",c,n);
		generate(input,n-1);
		if(n&1){
			input[0]=input[0]+input[n]-(input[n]=input[0]);
		}
		else{
			input[c]=input[c]+input[n]-(input[n]=input[c]);
		}
	}	
	
}
int main(){
	char input[]="ABC";
	int i,j;
	generate(input,2);
	return 0;
}
