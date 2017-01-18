#include<stdio.h>
int main(){
	char text[50],word[20],ch;
	int i,j,k,textn=0,subn;

	printf("\nEnter text :");
	while((ch=getchar())!='\n')
		text[textn++]=ch;
	
	printf("\nEnter word :");
	scanf("%s",word);
	for(subn=0;word[subn];subn++);
	for(i=0;i<textn-subn;i++){
		if(text[i]==word[0]){
			for(j=0,k=i;j<subn && (text[k]==word[j]);j++,k++);
			if(j==subn){
				printf("\nSubstring found at %d\n",i);
				return 0;
			}
		}
	}
						
	printf("\nSubstring not found \n");

	return 0;
}
