#include<stdio.h>
#include<string.h>
int main(){
	char text[20],pat[10],ch;
	int i,j,k,textN,patN,freqPat[26],freqText[26],count=0;
	printf("\nEnter text : ");
	scanf(" %[^\n]s",text);
	printf("\nEnter Pattern : ");
	scanf("%s",pat);
	for(i=0;i<26;i++)
		freqPat[i]=freqText[i]=0;
	for(i=0;pat[i];i++)
		freqPat[pat[i]-'A']++;
	for(i=0;i<strlen(pat);i++)
		freqText[text[i]-'A']++;
	for(i=0;i<26 && freqText[i]==freqPat[i];i++);
	if(i==26)
		count++;
	for(i=strlen(pat);text[i];i++){
		freqText[text[i-strlen(pat)]-'A']=0;
		freqText[text[i]-'A']++;
		if(freqPat[text[i]-'A']==freqText[text[i]-'A'])
			count++;
	}
	printf("\nCounter = %d",count);
	return 0;
}