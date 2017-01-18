#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main(){
	int i,j,n,k,num=0;
	char *s = (char*)malloc(65535*sizeof(char));
	printf("Integer Size : %lf",pow(2,sizeof(int)*8));
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%s",s);
		printf("String form :%s",s);
		num=0;
		for(j=0;j<strlen(s);j++){
			num=num*10+ (*(s+j)-'0');
			printf("Integer form :%d\n",num);
		}	
	}
	scanf("%d",&num);
	printf("Normal Integer Input : %d",num);
	printf("\n%ld\n",sizeof(int));
	return 0;
}
