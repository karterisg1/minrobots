#define MAX(a, b) ((a)>(b)?(a):(b))

extern int **createMatrix(int, int);
extern int **releaseMatrix(int **, int);
int **initializeMatrix(int **, int, int);
int fdp(int **, int **, int, int);
int solve(int, int, int **A);
void printPath(int **, int **, int, int, int, int);