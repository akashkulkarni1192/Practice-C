


for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ret[i, j] = matrix[n - j - 1, i];
            ret[i][j] = matrix[ j ][ n - 1 - i];
        }
    }


    1 2 3 4 3
    5 6 7 8 2 
    8 7 8 4 4
    5 3 8 1 5
    6 8 5 3 9
   00
   10 01
   20 11 02
   30 21 12 03
   40 31 22 13 04
   41 32 23 14
   42 33 24 
   43 34
   44



for(i=0;i<=4;i++)
	for(j=i,k=0; j>=0 && k<=n-1;j--,k++)
		print arr[j][k]
for(i=1;i<=4;i++)
	for(j=4,k=i;j>=0;k<=4;j--,k++)
		print arr[j][k]
