// 	hey thereey i am using whatsapp
//	hereey
//  hey
#include<stdio.h>
#include<string.h>
int main(){
	char string1[20],string2[10],string3[10];
	int i,j,k,m;
	fflush(stdin);
	scanf(" %[^\n]s",string1);
	scanf(" %[^\n]s",string2);
	scanf(" %[^\n]s",string3);
	fflush(stdin);
	for(i=0;string1[i];i++){
		for(j=0;string2[j]!='\0' && string2[j]==string1[i+j];j++);
		if(j==strlen(string2)){
			printf("\n %s found at %d in %s",string2,i,string1);
			for(k=i,m=0;string2[m] && string3[m];k++,m++)
				string1[k]=string3[m];
			printf("\n%s",string1);
			if(strlen(string2)>strlen(string3)){
				for(m=k;m<(strlen(string1)-(strlen(string2)-strlen(string3)));m++)
					string1[m]=string1[m+strlen(string2)-strlen(string3)];
				string1[m]='\0';
				printf("\n%s",string1);
			}
		}
	}
	printf("\nString is :\n%s\n",string1);
	return 0;
}