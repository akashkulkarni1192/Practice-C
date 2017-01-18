#include<stdio.h>
int main(){
	int arr[3][3],i,j,s=0,sum=0;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&arr[i][j]);
	for(j=0;j<3;j++)
		sum+=arr[0][j];
	for(i=1;i<3;i++){
		s=0;
		for(j=0;j<3;j++)
			s+=arr[i][j];
		if(s!=sum){
			printf("\nNot a magic square");
			return 0;
		}
	}
	for(j=0;j<3;j++){
		s=0;
		for(i=0;i<3;i++)
			s+=arr[i][j];
		if(s!=sum){
			printf("\nNot a magic square");
			return 0;
		}
	}
	s=0;
	for(i=0;i<3;i++)
		s+=arr[i][i];
	if(s!=sum){
			printf("\nNot a magic square");
			return 0;
	}
	s=0;
	for(i=0,j=2;i<3;i++,j--)
		s+=arr[i][j];
	if(s!=sum){
			printf("\nNot a magic square");
			return 0;
	}
	printf("\nMagic Square");
	return 0;
}