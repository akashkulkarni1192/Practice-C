#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	char str[50][20],pat1[20],pat2[20],ch;
	int n=0,i=0,j,min=999,ans,n1=0,n2=0,pos1=-1,pos2=-1,p1,p2;
	printf("\nEnter sentence : ");
	while((ch=getchar())!='\n'){
		if(ch==' '){
			str[i][n]='\0';
			i++;
			n=0;
		}
		else
			str[i][n++]=ch;
	}
	str[i][n]='\0';
	printf("\nEnter string 1 :");
	scanf("%s",pat1);
	printf("\nEnter string 2 :");
	scanf("%s",pat2);
	//printf("\n--%d--\n",strcmp(str[3],pat2));
	for(j=0;j<=i;j++){
		printf("\nstr[%d]=%s %s %s",j,str[j],pat1,pat2);
		printf("%d %d",strcmp(pat1,str[j]),strcmp(pat2,str[j]));
		if(strcmp(pat1,str[j])==0){
			pos1=j;
			printf("\npos1 = %d ",pos1);
		}
		if(strcmp(pat2,str[j])==0){
			pos2=j;
			printf("\npos2 = %d ",pos2);
		}
		if(pos1!=-1 && pos2!=-1 && min>abs(pos2-pos1)){
			printf("\nmin = %d ",abs(pos2-pos2));
			min=abs(pos2-pos1);
			p1=pos1;
			p2=pos2;
		}
	}
	printf("\nWords = %d \n\n",min-1);
	return 0;
}
