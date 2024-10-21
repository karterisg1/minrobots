#include<stdio.h>
#include "robotmem.h"

int fm(int **A, int **c, int n, int m, int i, int j) 
{
    if (c[i][j] != -1)
	{
		;
	}
    else if ((i == 0) && (j == 0)) 
	{
        c[i][j] = A[0][0];
    }
    else if ((i == 0) && (j < m)) 
	{
        c[i][j] = fm(A, c, n, m, i, j - 1) + A[i][j];
    }
    else if ((j == 0) && (i < n)) 
	{
        c[i][j] = fm(A, c, n, m, i - 1, j) + A[i][j];
    }
    else if ((i < n) && (j < m)) 
	{
        c[i][j] = MAX(fm(A, c, n, m, i, j - 1), fm(A, c, n, m, i - 1, j)) + A[i][j];
    }
	return c[i][j];
}

int **initializeMatrix(int **A, int n, int m)
{
	int i, j;
	
	for (i = 0; i < n; i++) 
	{
        for (j = 0; j < m; j++) 
		{
            A[i][j] = -1;
        }
    }
    return A;
}

int solve(int n, int m, int **A)
{
    int i, j, **c, coins;
	
	i = n - 1;
    j = m - 1;
	c = createMatrix(n, m);
	c = initializeMatrix(c, n, m);
    coins = fm(A, c, n, m, i, j);
	printf("Maximum number of coins to pick up is: %d\n", coins);
    printf("Path is: ");
    printPath(c, A, n, m, i, j); 
	c = releaseMatrix(c, n);
	return coins;
}

void printPath(int **c, int **A, int n, int m, int i, int j) 
{
	int flag = 0;
	
    if ((i == 0) && (j == 0)) 
	{
		flag = 1;
    } 
	else if ((i == 0) && (j < n)) 
	{
        printPath(c, A, n, m, i, j - 1);
    } 
	else if ((j == 0) && (i < n)) 
	{
        printPath(c, A, n, m, i - 1, j);
    } 
	else if ((i < n) && (j < m)) 
	{
        if (c[i][j - 1] == c[i][j]) 
		{
            printPath(c, A, n, m, i, j - 1);
        } 
		else if (c[i - 1][j] == c[i][j]) 
		{
            printPath(c, A, n, m, i - 1, j);
        } 
		else if (c[i - 1][j] == c[i][j] - 1) 
		{
            printPath(c, A, n, m, i - 1, j);
        } 
		else 
		{
            printPath(c, A, n, m, i, j - 1);
        }
    }
	if (A[i][j] == 1)
	{
        putchar('C');
	}
    else
	{
		putchar('.');
	}
    printf("(%d,%d)/%d --> ", i + 1, j + 1, c[i][j]);
	if (flag == 1)
	{
		return;
	}
}