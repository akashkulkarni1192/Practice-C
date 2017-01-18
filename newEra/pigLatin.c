#include<stdio.h>
#include<string.h>
int main(){
	char str[20],ans[30],pig;
	int i,k=0;
	scanf(" %[^\n]s",str);
	pig=str[0];
	for(i=1;str[i];i++){
		if(str[i]==' '){
			ans[k++]=pig;
			ans[k++]='a';
			ans[k++]='y';
			ans[k++]=' ';
			pig=str[i+1];
			i++;
		}else{
			ans[k++]=str[i];
		}
	}
	ans[k++]=pig;
	ans[k++]='a';
	ans[k++]='y';
	ans[k]='\0';
	printf("\n%s\n",ans);
	return 0;
}