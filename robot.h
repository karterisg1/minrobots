#define MAX(a, b) ((a)>(b)?(a):(b))

int **createMatrix(int, int);
int **fillMatrix(int *, int *);
int **releaseMatrix(int **, int);

extern int solve(int, int, int **);