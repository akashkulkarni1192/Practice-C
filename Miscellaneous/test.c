#include<stdio.h>
typedef struct stu{
	int x,y;
}S;
int main(){	
	int x=5,y=6;
	S s,p;
	s.x=5;
	s.y=9;
	printf("\ns %d %d",s.x,s.y);
	p=s;
	printf("\np %d %d",p.x,p.y);
	//printf("sum  = %d",printf("%*d%*d",x,x,y,y));
	return 0;
}
