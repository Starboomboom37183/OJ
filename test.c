#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

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
            ok[index[arr2[i]]] = 1;
        }
        int n = arr1.size();
        int dp[n][m] = {0};        
        for (int i = 0; i < n; i ++) {
            int state = 10000;
            if (i == 0) state = 0;
            for (int j = 0; j < m; j ++) {
                if (j == arr1[i]) {
                    dp[i][j] = state;
                } else if (ok[j]) {
                    dp[i][j] = state + 1;
                } else {
                    dp[i][j] = 10000;
                }
                if (i) {
                    state = min(state, dp[i-1][j]);
                }
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        int ans = n + 1;
        for (int i = 0; i < m; i ++) ans = min(ans, dp[n-1][i]);
        if (ans == n + 1) ans = -1;
        return ans;                
}

int main()
{
    vector<int> arr1 = {1,5,3,6,7};
    vector<int> arr2 = {1,4,3};
    int res = makeArrayIncreasing(arr1, arr2);
    cout<<res<<endl;
    return 0;
}