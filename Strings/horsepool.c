//		hey there i am using whatsapp
//		whats



#include<stdio.h>
int main(){
	char text[50],pat[20],ch;
	int shiftTab[26],i,j,k,n=0,patlen,pos,chars=0;
	printf("\nEnter Text :");
	while((ch=getchar())!='\n')
		text[n++]=ch;
	printf("\nEnter Pattern :");
	scanf("%s",pat);
	for(patlen=0;pat[patlen];patlen++);
	//preparing table
	for(i=0;i<26;i++)
		shiftTab[i]=-999;
	for(i=0;text[i];i++){
		pos=patlen;
		for(j=patlen-1,k=0;j>=0;j--,k++){
			if(text[i]==pat[j]){
				pos=k;
				break;
			}
		}
		shiftTab[text[i]-'a']=pos;
	}

	for(i=patlen-1;text[i];i++){
		for(k=patlen-1,j=i;k>=0;k--,j--){
			if(pat[k]==text[j]){
				chars++;
			}
			else
				break;
		}
		if(chars==patlen){
			printf("\nPattern Found");
			break;
		}
		else{
			printf("\n%c : moved by %d",text[j],shiftTab[text[j]-'a']);
			i=i+shiftTab[text[j]-'a']-1;	
		}
	}
	
	printf("\nProgram ends\n\n");
	return 0;
}	
	

	
	
	
