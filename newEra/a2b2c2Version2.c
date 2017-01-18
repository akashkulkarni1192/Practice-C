#include<stdio.h>
int main(){
	long double a,b,c,k,sum;
	scanf("%Lf",&k);
	for(a=0;a<=k;a++)
		for(b=a+1,c=k-1;b<c;){
			sum=a*a+b*b+c*c;
			if(a*a+b*b+c*c==k){
				printf("\na = %Lf\tb = %Lf\tc = %Lf",a,b,c);
				return 0;
			}
			else if(sum<k)
				b++;
			else
				c--;
		}
	return 0;
}