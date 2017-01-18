#include<stdio.h>
int main(){
	char str1[50],str2[20],str3[20],word[20],match[20],result[20];
	int i,j,left,right,l,r,found,flag,flagm,x,y,z,minlen=99,str2len;
	
	printf("\nEnter String 1 :");
	scanf("%s",str1);
	printf("\nEnter String 2 :");
	scanf("%s",str2);
	printf("\nEnter String 3 :");
	scanf("%s",str3);
	for(str2len=0;str2[str2len];str2len++);
	for(left=0;str1[left];left++){
		for(right=left;str1[right];right++){
			for(i=left;i<=right;i++){
				found=0;
				flag=0;
				for(x=left;x<=right;x++){
					for(y=0;str3[y];y++){
						if(str1[x]==str3[y]){
							flag=1;
							break;
						}
					}
				}
				if(flag!=1){
					found=0;
					for(x=0;str2[x];x++){
						for(y=left;y<=right;y++){
							if(str2[x]==str1[y]){
								flagm=0;
								for(z=0;match[z];z++){
									if(match[z]==str1[y]){
										flagm=1;
										break;
									}
								}
								if(flagm!=1){
									found++;
									break;
								}
							}
						}
					}
					if(found==str2len){
						if((right-left+1)<minlen){
							minlen=right-left+1;
							for(x=left,z=0;x<=right;x++,z++)
								result[z]=str1[x];
							result[z]='\0';
						}
					}
				}
			}
		}
	}

	printf("\nMin sequence :%s\n\n\n\n",result);
	return 0;
}	

	

