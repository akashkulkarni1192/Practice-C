#include<stdio.h>
int main(){
	long double a,b,c,k;
	scanf("%Lf",&k);
	for(a=0;a<=k;a++)
		for(b=0;b<=k;b++)
			for(c=0;c<=k;c++)
				if((a*a+b*b+c*c)==k)
					printf("\n a=%Lf\tb=%Lf\tc=%Lf",a,b,c);
	return 0;
}