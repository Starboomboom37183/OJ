// 分隔数组以得到最大和, 动态规划
#include <stdio.h>
int dp[505];
#define MAX(a,b) (a)>(b)?(a):(b)
int maxSumAfterPartitioning(int* A, int ASize, int K){
    dp[1] = A[0];
    for(int i = 0;i<=ASize;++i) {
        dp[i] = 0;
    }
    for (int i = 2;i<=ASize;++i) {
        for (int j = 1;j<=K;++j) {
            int max = 0;
            if(i-j<0) continue;
            for (int m = i-j;m < i;++m) {
                if (max < A[m]) {
                    max = A[m];
                }
            }
            dp[i] = MAX(dp[i], dp[i-j] + max * j);
        }
        
    }
    return dp[ASize];
}

int main() {
    int a[11] = {1,4,1,5,7,3,6,1,9,9,3};
    int res = maxSumAfterPartitioning(a,11,4);
    printf("%d\n", res);
    return 0;
}