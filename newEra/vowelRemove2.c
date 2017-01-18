// Thsi is bakash
//    .  
//     .

#include<stdio.h>
int main(){
	char str[20];
	int consPos,vowPos,i;
	scanf(" %[^\n]s",str);
	for(vowPos=0;str[vowPos]!='\0' && (str[vowPos]!='a' && str[vowPos]!='e' && str[vowPos]!='i' && str[vowPos]!='o' && str[vowPos]!='u');vowPos++);
	for(consPos=vowPos;str[consPos]!='\0' && (str[consPos]=='a' || str[consPos]=='e' || str[consPos]=='i' || str[consPos]=='o' || str[consPos]=='u');consPos++);
	for(i=0;str[i] && (vowPos<strlen(str));i++){
		str[consPos]=str[consPos]+str[vowPos]-(str[vowPos]=str[consPos]);
		for(;str[vowPos]!='\0' && (str[vowPos]!='a' && str[vowPos]!='e' && str[vowPos]!='i' && str[vowPos]!='o' && str[vowPos]!='u');vowPos++);
		for(consPos=vowPos;str[consPos]!='\0' && (str[consPos]=='a' || str[consPos]=='e' || str[consPos]=='i' || str[consPos]=='o' || str[consPos]=='u');consPos++);
	}
	printf("\nCleaned String : \n%s\n",str);
}    