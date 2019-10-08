#include <stdio.h>
#define MAX_LEN  (100002)
#define MAX(a, b)  ((a) > (b) ? (a) : (b))
// 动态规划
//最大连续子序列之和
int GetSum(int arr[], int arrSize) {
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

int maxSumAfterPartitioning(int* A, int ASize, int K){
    int dp[505];
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
int dp[100][500];
int beibao(int weight[], int value[], int W, int N) {
    for (int i = 1;i<=N;++i) {
        for (int j=0;j<=W;++j) {
            if (j < weight[i]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = MAX(dp[i-1][j], dp[i-1][j - weight[i]] + value[i]);
            }
        }
    }

    return dp[N][W];

}

// 背包问题为什么可以优化掉一维呢， 因为每一次只依赖于i-1的状态，这个是可以在上一次求出来的

int beibao2(int weight[], int value[], int W, int N) {
    int dp[500] = {0};
    for (int i = 1;i<=N;++i) {
        for (int j=W;j >= weight[i];--j) {  // 保证我们在调用上次的转态的时候， 没有被当前覆盖掉， 所以直接按照weight从大到小遍历即可
            dp[j] = MAX(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    return dp[W];

}

// 完全背包 可以拿多次 转移方程 dp[i][j] = max (dp[i-1][j], dp[i][j - weight[i]] + value[i]) 可以拿多次
int beibao3(int weight[], int value[], int W, int N) {
    int dp[500] = {0};
    for (int i = 1;i<=N;++i) {
        for (int j= weight[i];j<=W;++j) {  
            dp[j] = MAX(dp[j], dp[j - weight[i]] + value[i]); // 此处为正序， 可以引用前面的最新的状态
        }
    }

    return dp[W];

}

/* 多重背包问题限定了一种物品的个数，解决多重背包问题，只需要把它转化为0-1背包问题即可。
比如，有2件价值为5，重量为2的同一物品，我们就可以分为物品a和物品b，a和b的价值都为5，重量都为2，但我们把它们视作不同的物品。 */

// 最长递增子序列
/* 
    for(i = 0; i < length; i++){  
        b[i] = 1;  
        for(j = 0; j < i; j++){  
            if(a[i] > a[j] && b[i] <= b[j]){  
                b[i] = b[j] + 1;  
            }  
        }  
    }  
*/

/* 最长公共子序列 */
// leetcode 1035 不相交的线
#define MAX(a,b) ((a) > (b) ? (a) : (b))
int maxUncrossedLines(int* A, int ASize, int* B, int BSize){
    int dp[ASize+1][BSize+1];
    for (int i = 0;i <= ASize;++i) {
        for (int j = 0;j <= BSize;++j) {
            if (i ==0 || j==0) {
                dp[i][j] = 0;
                continue;
            }
            if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else {
                dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
            }

        }
    }

    return dp[ASize][BSize];
}

// 树状dp
class Solution {
public:
    
    TreeNode *solve(TreeNode *root) {
        if (root == NULL) return NULL;
        root->left = solve(root->left);
        root->right = solve(root->right);
        int l = root->left ? root->left->val : 0;
        int r = root->right ? root->right->val : 0;
        int ll = (root->left && root->left->left ? root->left->left->val : 0);
        int lr = (root->left && root->left->right ? root->left->right->val : 0);
        int rl = (root->right && root->right->left ? root->right->left->val : 0);
        int rr = (root->right && root->right->right ? root->right->right->val : 0);
        root->val = max(root->val + ll + lr + rl + rr, l + r);
        return root;
    }
    
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        TreeNode *res = solve(root);
        return res->val;
    }
};


int main() {
    int value[] = {0, 8 , 10 , 4 , 5 , 5};       
    int weight[] = {0, 6 , 4 , 2 , 4 , 3};     
    int res = beibao3(weight, value, 10, 5);
    printf("%d\n", res);
    return 0;
}