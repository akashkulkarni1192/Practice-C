#include<stdio.h>
int main(){
	char str1[50],str2[50],str3[50],ch;
	int i,j,n=0,n2,n3,k,pos;
	printf("\nEnter String1 :");
	while((ch=getchar())!='\n')
		str1[n++]=ch;
	printf("\nEnter String2 :");
	scanf("%s",str2);
	for(n2=0;str2[n2];n2++);
	printf("\nEnter String3 :");
	scanf("%s",str3);
	for(n3=0;str3[n3];n3++);
	j=0;
	for(i=0;str1[i];i++){
		if(str1[i]==str2[j])
			j++;
		else
			j=0;
		if(j==n2){
			printf("\nPattern Matched at %d location ",i-n2+1);
			break;
		}
	}
	pos=i-n2+1;
	for(j=i+1;j<n;j++){
		printf("\nstr1[%d]=str1[%d]=%c",j-n2,j,str1[j]);
		str1[j-n2]=str1[j];
	}
	str1[n-n2]='\0';
	printf("\nString 2 removed : %s",str1);
	for(i=n-n2-1;i>=pos;i--)
		str1[i+n3]=str1[i];
	for(i=pos,j=0;i<pos+n3;i++,j++)
		str1[i]=str3[j];
	str1[n-n2+n3]='\0';
	printf("\nReplaced : %s\n\n",str1);
	return 0;
}
