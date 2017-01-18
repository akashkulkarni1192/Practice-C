#include<stdio.h>
int main(){
	char str[50],ch;
	int n=0,i,j;
	printf("\nEnter String : ");
	while((ch=getchar())!='\n')
		str[n++]=ch;
	str[n]='\0';
	for(i=1;str[i];i++){
		if(str[i]==str[i-1]){
			for(j=i--;j<n;j++)
				str[j]=str[j+1];
			str[j]='\0';
			n--;
		}
	}
	printf("\nResult : %s\n",str);
	return 0;
}
