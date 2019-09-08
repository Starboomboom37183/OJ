#include <stdio.h>
int visited[1000][1000];
int max(int a,int b) {
    return a>b ? a:b;
}

int dfs(int **matrix,int i, int j, int row, int col, int lastValue) {
    if (i<0 || i>= row || j < 0 || j >= col) return 0;
    int curValue = matrix[i][j];
    if (curValue <= lastValue) return 0;
    int up, down, left, right;
    if (!visited[i][j]) {
        up = dfs(matrix, i-1,j, row, col, curValue);
        down = dfs(matrix, i + 1,j, row, col, curValue);
        left = dfs(matrix, i,j -1, row, col, curValue);
        right = dfs(matrix, i,j+1, row, col, curValue);
        visited[i][j] = 1 + max(max(up, down), max(left, right));
    }
    return visited[i][j];
} 

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
    int col =  matrixColSize[0];
    int row = matrixSize / col;
    int max = 0;
    for (int i=0;i<row;++i) {
        for (int j=0;j<col;++j) {
            int temp = dfs(matrix,i,j,row, col, 0);
            if (temp > max) {
                max = temp;
            }
        }
    }
    return max;
}


int main () {
    int mSize;
    int row;
    int col;
    while (scanf_s("%d %d", &row, &col)!=EOF) {
        int **p = (int **)malloc(sizeof(int *) * row);
        int *mColSize = (int *)malloc(sizeof(int) * row);
        for (int i = 0; i < row; ++i)
        {
            p[i] = (int *)malloc(sizeof(int) * col);
            mColSize[i] = col;
        }

        for (int i =0; i<row;++i) {
            for (int j = 0;j<col;++j) {
                scanf_s("%d", &p[i][j]);
            }
        }
        mSize = row * col;
        int res = longestIncreasingPath(p,mSize, mColSize);
        printf("%d\n", res);

    } 
    return 0;
}