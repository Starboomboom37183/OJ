// 24点
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool Point24(double *nums, int n) {
    if (n==1) {
        if (fabs(nums[0] - 24) < 1e-6) {
            return true;
        }
    } else {
        for (int i =0;i<n;++i) {
            for (int j =i+1;j<n;++j) {
                double a = nums[i];
                double b = nums[j];
                nums[j] = nums[n-1];
                for (int k = 0;k<6;++k) {
                    if (k==0) nums[i] = a + b; 
                    else if (k==1) nums[i] = a - b;
                    else if (k==2) nums[i] = b - a;
                    else if (k==3) nums[i] = a * b;
                    else  if (k==4){
                        if (b==0) continue;
                        nums[i] = a / b;
                    } else {
                        if (a==0) continue;
                        nums[i] = b / a;
                    }
                    if (Point24(nums, n-1)) return true;
                }
                nums[i] = a;
                nums[j] = b ;
            }
        }
    }
    return false;
}

bool judgePoint24(int* nums, int numsSize){
    double newArray[4];
    for (int i = 0;i<4;++i) {
        newArray[i] = (double)nums[i];
    }
    return Point24(newArray, 4);
}
int main() {
    int a[4] = {0};
    while (scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3])!=EOF) {
        if (judgePoint24(a,4)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    // printf("%d\n", INT_MIN);
    return 0;
}