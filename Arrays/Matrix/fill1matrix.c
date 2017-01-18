#include<stdio.h>
int main(){
	int mat[10][10],i,j,k=0,m,n,arri[10],arrj[10];
	printf("\nEnter order(m x n) :");
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
			if(mat[i][j]){
				arri[k]=i;
				arrj[k++]=j;
			}
		}
	for(i=0;i<k;i++){
		for(j=0;j<n;j++)
			mat[arri[i]][j]=1;
		for(j=0;j<m;j++)
			mat[j][arrj[i]]=1;
	}
	printf("\nMatrix :\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}
	printf("\n\n");
	return 0;
}
	
