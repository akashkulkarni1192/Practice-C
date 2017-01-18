#include<stdio.h>
#include<string.h>
int main(){
	char str[20][20],common[20],com[20];
	int i,j,k=0,n,m;
	printf("\nEnter #strings : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf(" %s",str[i]);
	for(i=0;str[0][i];i++)
		for(j=0;str[1][j];j++)
			if(str[0][i]==str[1][j])
				common[k++]=str[0][i];
	common[k]='\0';
	strcpy(com,common);
	for(i=1;i<n;i++){
		m=0;
 	    for(j=0;j<str[i][j];j++)
 	    	for(k=0;com[k];k++)
 	     		if(com[k]==str[i][j])
 	     			common[m++]=com[k];
 	    common[m]='\0';
 	    strcpy(com,common);
	}
	for(i=0;i<m-1;i++){
		if(com[i]==com[i+1]){
			for(j=i;j<m-1;j++){
				com[j]=com[j+1];
			}
			com[m-1]='\0';
			m--;
			i--;
		}
	}
	printf("\nCommon characters : %s\n",com);
	return 0;
}