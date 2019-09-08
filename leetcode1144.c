#include <stdlib.h>
int movesToMakeZigzag(int* nums, int numsSize){
    if (numsSize == 1 || numsSize == 2) return 0;
    int min1 = 0;
    int min2 = 0;
    for (int i = 0;i < numsSize;++i) {
        int left = 0;
        int right = 0;
        if (i%2 == 0) {
            if (i+1 < numsSize && nums[i] >= nums[i+1]) {
                right = nums[i] - nums[i+1] + 1;
            }
            if (i-1>=0 && nums[i]>=nums[i-1]) {
                left = nums[i] - nums[i-1] + 1;
            }
            min1 += (left > right) ? left : right;

        } else {
            if (i+1 < numsSize && nums[i] >= nums[i+1]) {
                right = nums[i] - nums[i+1] + 1;
            }
            if (i-1>=0 && nums[i]>=nums[i-1]) {
                left = nums[i] - nums[i-1] + 1;
            }
            min2 += (left > right) ? left : right;

        }


    }

    return min1 < min2 ? min1 : min2;
}
int main() {
    int a[5] =  {9,6,1,6,2};
    int res = movesToMakeZigzag(a,5);
    return 0;
}