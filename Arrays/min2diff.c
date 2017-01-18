#include<stdio.h>
#include<math.h>
int main(){
	int arr[10],i,j,k,n,n1,n2,min=99;
	printf("\nEnter n :");
	scanf("%d",&n);
	printf("\nEnter %d elements :",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("\nEnter 2 elements :");
	scanf("%d %d",&n1,&n2);
	for(i=0;i<n;i++){
		if(arr[i]==n1){
			j=k=0;
			while(j<n){
				for(j=k;arr[j]!=n2;j++);
				if(j<n)
					printf("\n%d found at %d",n2,j);
				if(min>abs(i-j))
					min=abs(i-j);
				k=j+1;
			}
		}
	}
	printf("\nDistance :%d",min);
	return 0;
}
	
