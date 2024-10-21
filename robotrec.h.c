#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a)>(b)?(a):(b))

int **createMatrix(int, int);
int **fillMatrix(int *, int *);
int **releaseMatrix(int **, int);
int f(int, int, int **A, int, int);
int solve(int, int, int **A);
int isValid(int, int, int, int);

int main(void)
{
    int n, m;
    int coins;
	int **A = NULL;
	
	A = fillMatrix(&n, &m);
    coins = solve(n, m, A);
    printf("Maximum number of coins to pick up is: %d\n", coins);
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

int isValid(int i, int j, int n, int m)
{
	return (i >= 0 && i < n && j >= 0 && j < m);
}

int solve(int n, int m, int **A)
{
	return f(n-1, m-1, A, n, m); 
}

int f(int i, int j, int **A, int n, int m)
{
	int x;
	int y;

	if (!isValid(i, j, n, m))
		return 0;	

	x = f(i-1, j, A, n, m);
	y = f(i, j-1, A, n, m);
	return MAX(x, y) + A[i][j]; 
}