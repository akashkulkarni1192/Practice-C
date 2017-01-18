#include<stdio.h>
#include<string.h>

//Ths is bakash
//    .

int main(){
	char str[20];
	int i,j,k=0,n;
	scanf(" %[^\n]s",str);
	n=strlen(str);
	for(i=0;i<n;i++)
		if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
			for(j=i;j<=n-1;j++)
				str[j]=str[j+1];
			printf("\n-- %s",str);
			str[n-1]='\0';
			n--;
			i--;
		}
	printf("\nCleaned String : \n%s\n",str);
	return 0;
}