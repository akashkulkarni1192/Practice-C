#include<stdio.h>
#include<string.h>
int main(){
	char str[50],pat1[20],pat2[20],ch;
	int n=0,i,j,l1=0,l2=0,p1=-9999,p2=9999,min=999,q1,q2;
	printf("\nEnter String :");
	while((ch=getchar())!='\n')
		str[n++]=ch;
	str[n]='\0';
	printf("\nEnter string 1 :");
	scanf("%s",pat1);
	printf("\nEnter string 2 :");
	scanf("%s",pat2);
	for(i=0;str[i];i++){
		if(str[i]==pat1[l1]){
			l1++;
			if(l1==strlen(pat1) && (str[i+1]==' ' || str[i+1]=='\0'  ) && (str[i-strlen(pat1)]==' ' || i-strlen(pat1)==-1)){
				printf("\np1= %d ",i);
				p1=i;
			}
		}
		else
			l1=0;
		if(str[i]==pat2[l2]){
			l2++;
			if(l2==strlen(pat2) && (str[i+1]==' ' || str[i+1]=='\0'  ) && (str[i-strlen(pat2)]==' ' || i-strlen(pat2)==-1)){
				printf("\np2= %d ",i);
				p2=i;
			}
		}
		else
			l2=0;
		if(abs(p2-p1)<min){
			min=abs(p2-p1);
			printf("\nMin = %d ",min);
			q1=p1;
			q2=p2;
			printf("\nq1= %d, q2=%d",q1,q2);
		}
	}
	printf("\nT -> %d",p2-strlen(pat2)+1-p1);
	printf("\nF -> %d",p1-strlen(pat1)+1-p2);
	printf("\nMin chars : %d\n\n",((q2>q1)?q2-strlen(pat2)+1-q1-1:q1-strlen(pat1)+1-q2-1));
	return 0;
}
		
