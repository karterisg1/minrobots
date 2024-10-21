#include <stdio.h>
#include <stdlib.h>
#include "robot.h"

int main(void)
{
    int n, m;
    int coins;
	int **A = NULL;
	
	A = fillMatrix(&n, &m);
    coins = solve(n, m, A);
    A = releaseMatrix(A, n);
    return 0;
}

int **createMatrix(int n, int m)
{
	int **x;
	int i;
	
	x =  (int **) malloc(n * sizeof(int *));
	if (x == NULL)
	{
		fprintf(stderr, "Cannot allocate memory. Aborting program.\n");
		exit(1);
	}
    for (i = 0; i < n; i++)
	{
        x[i] = (int *)calloc(m, sizeof(int));
        if (x[i] == NULL)
		{
			fprintf(stderr, "Cannot allocate memory. Aborting program.\n");
			exit(1);
		}	
	}
	return x;
}
int **fillMatrix(int *n, int *m)
{
	int **A, c, i, j;
	
	scanf("%d", n);
	scanf("%d", m);
	c = getchar();
	
	A =  createMatrix(*n, *m);
	for (i = 0; i < (*n); i++)
	{
		for (j = 0; j < (*m); j++)
		{
			c = getchar();
			if (c == 'C')
			{
				A[i][j] = 1;
			}
		}
		c = getchar();
    }
	return A;
}

int **releaseMatrix(int **A, int n)
{
	int i;
	
	for (i = 0 ; i < n ; i++)
	{
         free(A[i]);
    }
    free(A);
    return NULL;
}
