//		hey there i am using whatsapp
//		                     whats

#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main(){
	char string[20],substring[10],ch;
	int i,j,k,n,table[26];
	scanf(" %[^\n]s",string);
	scanf(" %[^\n]s",substring);
	for(i=0;i<26;i++)
		table[i]=-999;
	for(i=0;string[i];i++){
		for(j=strlen(substring)-1;j>=0;j--){
			if(string[i]==substring[j]){
				table[string[i]-'a']=strlen(substring)-1-j;
				break;
			}
		}
		printf("\nfor %c j value returned at j = %d",string[i],j);
		if(j==-1)
			table[string[i]-'a']=strlen(substring);
	}
	for(i=strlen(substring)-1;string[i];i++){
		for(k=i,j=strlen(substring)-1;j>=0;j--,k--){
			printf("\nj = %d",j);
			if(string[k]!=substring[j]){
				i=i+table[string[k]-'a']-1;
				break;
			}
		}
		if(j==-1){
			printf("\nMatched ");
			break;
		}
	}

	return 0;
}