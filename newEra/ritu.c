#include<stdio.h>
#include<math.h>
int main(){
	long N;
	long a,b,c,sum;
	printf("Enter N:\n");
	scanf("%ld",&N);
	
	for(a=0;a<2237;a++){
		b=a+1;
		c=2237-1;
		while(b<c){
			sum=a*a+b*b+c*c;
			if(sum==N){
				printf("%d %d %d\n",a,b,c);
				break;
			}else if(sum<N){
				b++;
			}else{
				c--;
			}
		}
			
	}
	
	return 0;
}