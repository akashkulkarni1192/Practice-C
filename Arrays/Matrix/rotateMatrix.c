#include<stdio.h>
int main(){
	int matrix[10][10],res[10][10],i,j,m,layer,temp;
	printf("\nEnter order( m ) :");
	scanf("%d",&m);
	printf("\nEnter elements :");
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
			scanf("%d",&matrix[i][j]);
	printf("\nRight Rotation :\n\n");
	for(i=0;i<m;i++){
		for(j=m-1;j>=0;j--)
			printf("\t%d",matrix[j][i]);
		printf("\n");
	}
	printf("\nLeft Rotation :\n\n");
	for(i=m-1;i>=0;i--){
		for(j=0;j<m;j++)
			printf("\t%d",matrix[j][i]);
		printf("\n");
	}
	return 0;
}

