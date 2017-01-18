#include<stdio.h>
int main(){
	char str1[20],str2[20],ch;
	int i,j,freq1[26],freq2[26];
	printf("\nEnter String 1 :");
	scanf("%s",str1);
	printf("\nEnter String 2 :");
	scanf("%s",str2);
	for(i=0;i<26;i++){
		freq1[i]=freq2[i]=0;
	}
	for(i=0;str1[i]!='\0' && str2[i]!='\0';i++){
		freq1[str1[i]-'a']++;
		freq2[str2[i]-'a']++;
	}
	for(i=0;i<26;i++){
		if(freq1[i]!=freq2[i]){
			printf("\nNot anagrams");
			return 0;
		}
	}
	printf("\nAnagrams ");
	return 0;
}
