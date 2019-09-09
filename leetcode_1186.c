#include <stdio.h>
#define MAX_LEN  (100002)
#define MAX(a, b)  ((a) > (b) ? (a) : (b))
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
int main() {
    // int arr[17] = {8,-1,4,13,-14,-13,16,-1,-14,9,-6,-17,-8,-1,-2,3,2};  //预期27
     // int arr[4] = {-1,-1,-1,-1};
     // int arr[4] = {1,-2,-2,3};
     int arr[4] = {1,-2,0,3};
    int res = maximumSum(arr, 4);
    printf("%d\n", res);
    return 0;
}