#include<stdio.h>
int main(){ 
	int i,j,t=0,pos;
	char str[20];
	scanf("%s",str);
	for(i=0;str[i];i++){
		pos=str[i]-'a';
		if(t&(1<<pos)){
			printf("\nDuplicate character present\n");
			return 0;
		}else
			t|=(1<<pos);
	}
	printf("\nNo Duplicates Found\n");
	return 0;
}