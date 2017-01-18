#include<stdio.h>
#include<ctype.h>
int main(){
	int num1[20],num2[20],num[20];
	int n1=0,n2=0,i,j,k=0,sum=0,carry=0;
	char ch;
	printf("\nEnter number : " );
	while((ch=getchar())!='\n')
		num1[n1++]=ch-'0';
	num[n1]='\0';
	while((ch=getchar())!='\n')
		num2[n2++]=ch-'0';
	num2[n2]='\0';
	for(i=n1-1,j=n2-1;i>=0 && j>=0;i--,j--){
		sum=num1[i]+num2[j]+carry;
		num[k++]=sum%10;
		carry=sum/10;
	}
	if(i==-1){
		for(;j>=0;j--){
			sum=num2[j]+carry;
			num[k++]=sum%10;
			carry=sum/10;
		}
	}else{
		for(;i>=0;i--){
			sum=num1[i]+carry;
			num[k++]=sum%10;
			carry=sum/10;
		}
	}
	if(carry)
		num[k++]=carry;
	num[k]='\0';
	printf("\nResult number : \n");
	for(i=k-1;i>=0;i--)
		printf("%d ",num[i]);
	return 0;
}