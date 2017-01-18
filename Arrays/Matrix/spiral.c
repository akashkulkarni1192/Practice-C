#include<stdio.h>
int main(){
	int matrix[10][10],m,n,i,j,left,right,up,down;
	printf("\nEnter order(m x n) :");
	scanf("%d %d",&m,&n);
	printf("\nEnter Elements :");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&matrix[i][j]);
	left=0;
	right=n-1;
	up=0;
	down=m-1;
	while(up<=down && left<=right){
		for(i=left;i<=right && up<=down;i++)
			printf("\n1st-\tmatrix[%d][%d]=%d",up,i,matrix[up][i]);
		up=up+1;
		for(i=up;i<=down && left<=right;i++)
			printf("\n2nd-\tmatrix[%d][%d]=%d",i,right,matrix[i][right]);
		right=right-1;
		for(i=right;i>=left && up<=down;i--)
			printf("\n3rd-\tmatrix[%d][%d]=%d",down,i,matrix[down][i]);
		down=down-1;
		for(i=down;i>=up && left<=right;i--)
			printf("\n4th-\tmatrix[%d][%d]=%d",i,left,matrix[i][left]);
		left=left+1;
	}
	return 0;
}
