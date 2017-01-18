//	This is a book
//  book a is    


#include<stdio.h>
#include<string.h>
int main(){
	char str[20],ans[20],ch;
	int i,j,k=0,n,pos1,pos2;
	scanf(" %[^\n]s",str);
	pos2=strlen(str);
	for(i=strlen(str)-1;i>=0;i--){
		if(str[i]==' '){
			pos1=i;
			for(j=pos1+1;j<pos2;j++)
				ans[k++]=str[j];
			ans[k++]=' ';
			pos2=pos1;
		}
	}
	for(j=0;j<pos2;j++)
		ans[k++]=str[j];
	ans[k]='\0';
	printf("Ans = %s",ans);
	return 0;
}