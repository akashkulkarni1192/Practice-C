#include<stdio.h>
int main(){
	char str[20],tempstr[20],ch;
	int i,j,k=0,n=0,rn,spacepos;
	printf("\nEnter String :");
	while((ch=getchar())!='\n')
		str[n++]=ch;
	spacepos=n;
	for(i=n-1;i>=0;i--){
		if(str[i]==' '){
			for(j=i+1;j<=spacepos-1;j++)
				tempstr[k++]=str[j];
			tempstr[k++]=' ';
			spacepos=i;
		}
	}
	for(j=i+1;j<=spacepos-1;j++)
		tempstr[k++]=str[j];
	tempstr[k]='\0';
	for(rn=0;tempstr[rn];rn++);
	printf("\nResultant String : %s \n\n",tempstr);
	return 0;
}
			
				
