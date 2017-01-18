#include<stdio.h>
struct st
{
int (*fptr)( );
};
int display( ) 
{
printf( "Hello World\n" );
}

int main( )
{
struct st s;
s.fptr = display;
s.fptr( );
}
