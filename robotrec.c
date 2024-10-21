#include "robotrec.h"

int f(int **A, int n, int m, int i, int j) 
{
    if ((i == 0) && (j == 0))
	{
		return A[0][0];
	}
    if ((i == 0) && (j < m))
	{
        return f(A, n, m, i, j - 1) + A[i][j];
	}
    if ((j == 0) && (i < n))
	{
        return f(A, n, m, i - 1, j) + A[i][j];
	}
    if ((i < n) && (j < m))
	{
        return MAX(f(A, n, m, i, j - 1), f(A, n, m, i - 1, j)) + A[i][j];
	}
}

int solve(int n, int m, int **A)
{
    int i, j, coins;
	
	i = n - 1;
    j = m - 1;
    coins = f(A, n, m, i, j);
	printf("Maximum number of coins to pick up is: %d\n", coins);
	return coins;
}
