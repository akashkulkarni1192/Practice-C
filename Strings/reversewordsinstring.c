#include<stdio.h>
int main(){
	char str[20],ch;
	int i=0,j,n,pos1=0,pos2;
	printf("\nEnter String :");
	//scanf("%[^n]",str);
	while((ch=getchar())!='\n')
		str[i++]=ch;
	printf("\nEntered String : %s",str);
	for(n=0;str[n];n++);
	//finding space
	for(i=0;str[i];i++){
		printf("\n i=%d char=%c",i,str[i]);
		if(str[i]==' '){
			pos2=i-1;
			printf("\npos1=%d pos2=%d",pos1,pos2);

			while(pos2>pos1){
				printf("\nswapping %c and %c",str[pos1],str[pos2]);
				str[pos1]=str[pos1]+str[pos2]-(str[pos2]=str[pos1]);
				pos2--;
				pos1++;	

			}
			
			/*for(j=pos1;j<=pos1+(pos2-pos1)/2;j++){
				printf("\nSwapping %c and %c",str[j],str[pos2-pos1-1-j+pos1]); 	
				str[j]=str[j]+str[pos2-pos1-1-j+pos1]-(str[pos2-pos1-1-j+pos1]=str[j]);
			}*/
			pos1=i+1;
		}
	}

	//reversing last word
	pos2=i-1;
	printf("\npos1=%d pos2=%d",pos1,pos2);

	while(pos2>pos1){
		printf("\nswapping %c and %c",str[pos1],str[pos2]);
		str[pos1]=str[pos1]+str[pos2]-(str[pos2]=str[pos1]);
		pos2--;
		pos1++;	
	}
	printf("\nReversed String : %s\n",str);
	return 0;
}

	
