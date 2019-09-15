// leetcode 265.c  粉刷房子

int minCostII(int** costs, int costsSize, int* costsColSize) {
    if (costsSize==0) return 0;  //好坑啊
    int min[costsSize];
    int secondMin[costsSize];
    int col = costsColSize[0];
    int dp[1000][1000] = {0};
    int min1,min2;
    for (int i = 0;i<costsSize;++i) {
        min[i] = -1;
        secondMin[i] = -1;
        min1 = 10000;
        min2 = 10000;
        for (int j = 0; j <col;++j) {
            if (i==0) {
                dp[i][j] = costs[i][j];
            } else {
                if (min[i-1]==j) {
                    dp[i][j] = dp[i-1][secondMin[i-1]] + costs[i][j];
                } else {
                    dp[i][j] = dp[i-1][min[i-1]] + costs[i][j];
                }
            }

            if (min1 > dp[i][j]) {
                secondMin[i] = min[i];
                min[i] = j;
                min2 = min1;
                min1 = dp[i][j];
            } else if (min2 > dp[i][j]) {
                secondMin[i] = j;
                min2 = dp[i][j];
            }
        }
    }
    return min1;
}
int main() {
    int costs[][3] = {{1,5,3},{2,9,4}};
    int colSize[3] = {3,3,3};
    int res = minCostII(costs, 2, colSize);
    return 0;
}
