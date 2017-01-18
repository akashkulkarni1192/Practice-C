#include<stdio.h>
int main(){
	static int n=5;
	printf("\nDone %d", n);
	if(--n)
		main();
	printf("\n");
	return 0;
}
