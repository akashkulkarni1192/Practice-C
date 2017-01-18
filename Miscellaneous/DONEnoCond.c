#include<stdio.h>
int main(){
	static int n=5;
	int check;
	check=1/n--;
	printf("DONE %d\n",n+1);
	//main(1/n--);
	main();
	return 0;
}
	
	
