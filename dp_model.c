#include <stdio.h>
#define MAX_LEN  (100002)
#define MAX(a, b)  ((a) > (b) ? (a) : (b))
// 动态规划
//最大连续子序列之和
int GetSum(int a[], int arrSize) {
    int dp[MAX_LEN] = {0};
    int ans = arr[0];
    dp[0] = arr[0];
    for (int i = 1;i < arrSize;++i) {
        dp[i] = MAX(dp[i-1] + arr[i], arr[i]);
        ans = MAX(ans,dp[i]);
    }
    return ans;
}

// 删掉一个元素  leetcode 1186
int maximumSum(int* arr, int arrSize)
{

    if (arr == NULL) return 0;
    if (arrSize == 1) return arr[0];
    int dp1[MAX_LEN] = {0};
    int dp2[MAX_LEN] = {0};
    dp1[0] = arr[0];
    for (int i=1;i<arrSize;++i) {
        dp1[i]  = MAX (dp1[i-1] + arr[i], arr[i]);
    }
    dp2[arrSize-1] = arr[arrSize-1];
    for (int i = arrSize-2;i>=0;i--) {
        dp2[i] = MAX(dp2[i + 1] + arr[i], arr[i]);
    }

    int max_res = -10000;
    for (int i=0;i<arrSize;++i) {
        if (i==0)
            max_res = MAX(max_res, dp2[i+1]);
        else if (i==arrSize -1) {
            max_res = MAX(max_res, dp1[i-1]);
        } else {
            max_res = MAX(max_res, dp1[i-1] + dp2[i+1]);
            int temp = MAX (dp1[i-1], dp2[i+1]);
            max_res = MAX(max_res, temp);
        }
    }
    return max_res;
}

// 爬楼梯
int climbStairs(int n){
    if (n==1 || n==2) return n;
    int dp[1000];
    dp[1] = 1;
    dp[2] = 2;
    for (int i=3;i<=n;++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// leetcode 1043
int dp[505]; 
int maxSumAfterPartitioning(int* A, int ASize, int K){
    for(int i = 0;i<=ASize;++i) {
        dp[i] = 0;
    }
    dp[1] = A[0];
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


// 01背包问题





int main() {
    return 0;
}