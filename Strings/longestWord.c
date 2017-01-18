#include<stdio.h>
int main(){
	char str[50],word[20],ch;
	int i,j,n=0,space1=-1,space2,max=0,s1=space1,s2;
	printf("\nEnter String :");
	while((ch=getchar())!='\n')
		str[n++]=ch;
	str[n]='\0';
	for(space2=0;str[space2]!=' ';space2++);
	s2=space2;
	max=space2-space1;
	printf("\nword(%d-%d)",space1,space2);
	for(i=space2+1;str[i];i++){
		if(str[i]==' '){
			space1=space2;
			space2=i;
			printf("\nword(%d-%d)",space1,space2);
			if(max<space2-space1){
				max=space2-space1;
				s2=space2;
				s1=space1;
			}
		}
	}
	space1=space2;
	space2=i;
	if(max<space2-space1){
		max=space2-space1;
		s2=space2;
		s1=space1;
	}
	printf("\nLongest word(%d-%d) : ",s1,s2);
	for(i=s1+1;i<s2;i++)
		printf("%c",str[i]);
	printf("\n\n");
	return 0;
}
	
