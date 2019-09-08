// leetcode竞赛153
#include <stdio.h>
int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){
    int zhengxiang = 0;
    int nixiang = 0;
    for (int i = start;(i  % distanceSize)!=destination;++i) {
        zhengxiang += distance[i % distanceSize];
    }
    int totalSum = 0;
    for (int i = 0; i < distanceSize;++i) {
        totalSum+=distance[i];
    }
    nixiang = totalSum - zhengxiang;
    return (zhengxiang > nixiang ? nixiang : zhengxiang);
}
// 计算每一个日期对应的是周几
char weekday[7][20] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
char * dayOfTheWeek(int d, int m, int y){
    if(m==1||m==2) {
        m+=12;
        y--;
    }
    int iWeek=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    return  weekday[iWeek];
}

// 删除一次得到子数组的最大和
int maximumSum(int* arr, int arrSize){
    
    if(arr == NULL || arrSize == 0) return -1;
    int sum = 0;
    int index = 0;
    int max = arr[index];
    int delete_count = 1;
    int min = 100000;
    int count = 0;
    int midSum = 0;
    for(index = 0;index < arrSize;++index)
    {
        sum = sum + arr[index];
        count++;
        if (count == 1) {
            if (sum > max) {
                max = sum;
            }
            if(sum < 0)
            {
                sum = 0;
                min = 10000;
                delete_count = 1;
                count = 0;
            } else {
                min = arr[index];
            }
            continue;
        }
        if (sum < 0) {
            if (delete_count==1) {
                if (min > arr[index]) {
                    min = arr[index];
                }
                sum = sum - min;
                delete_count--;
                midSum =  sum;
                min  = 10000;
                if (sum > max) {
                    max = sum;
                }
            }
        } else {
            if (min > arr[index]) {
                min = arr[index];
            }
            if (delete_count == 1) {
                if (sum - min > max) {
                    max = sum - min;
                }
            } else {
                if (midSum < min*(-1) && delete_count ==0) {
                    sum = sum - midSum;
                    if (sum - min  > max) {
                        max = sum;
                    }
                    delete_count = 1;
                } else {
                    if(sum > max) {
                        max = sum;
                    }
                }
            }
        }
        if(sum < 0)
        {
            sum = 0;
            min = 10000;
            delete_count = 1;
            count = 0;
        }

    }
    return max;
}


int main() {
    int arr[17] = {8,-1,4,13,-14,-13,16,-1,-14,9,-6,-17,-8,-1,-2,3,2};  //预期27
    // int arr[4] = {1,-2,-2,3};
    int res = maximumSum(arr, 17);
    printf("%d\n", res);
    return 0;
}

// 第四题
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        vector<int> nums;
        for (auto i : arr1) nums.push_back(i);
        for (auto i : arr2) nums.push_back(i);
        sort(nums.begin(), nums.end());
        map<int, int> index;  
        int m = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (i == 0 || nums[i] != nums[i-1]) {
                index[nums[i]] = m++;
            }
        }
        
        int ok[m] = {0};
        for (int i = 0; i < arr1.size(); i ++) {
            arr1[i] = index[arr1[i]];
        }
        for (int i = 0; i < arr2.size(); i ++) {
            ok[index[arr2[i]]] = true;
        }
        int n = arr1.size();
        int dp[n][m] = {0};        
        for (int i = 0; i < n; i ++) {
            int state = n + 1;
            if (i == 0) state = 0;
            for (int j = 0; j < m; j ++) {
                if (j == arr1[i]) {
                    dp[i][j] = state;
                } else if (ok[j]) {
                    dp[i][j] = state + 1;
                } else {
                    dp[i][j] = n +1;
                }
                if (i) {
                    state = min(state, dp[i-1][j]);
                }
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        int ans = n + 1;
        for (int i = 0; i < m; i ++) ans = min(ans, dp[n-1][i]);
        if (ans == n + 1) ans = -1;
        return ans;                
    }
};