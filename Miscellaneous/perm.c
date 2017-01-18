/* Function to swap values at two pointers */
#include<stdio.h>
void swap (char *x, char *y)
{
    printf("%c <-> %c\n",*x,*y);
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
  
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n) 
{
   int j; 
   if (i == n)
     printf("%s\n", a);
   else
   {
        for (j = i; j <= n; j++)
       {
	  printf("\nU:");
          swap((a+i), (a+j));
          permute(a, i+1, n);
	  printf("\nD:");
          swap((a+i), (a+j)); //backtrack
       }
   }
} 
int main()
{
   char a[] = "ABC";  
   permute(a, 0, 2);
   getchar();
   return 0;
}