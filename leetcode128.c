#include <stdlib.h>
#define MAX_SIZE 10000
int longestConsecutive(int* nums, int numsSize){
    int map[MAX_SIZE] = {-1};
    for (int i=0;i<numsSize;++i) {
        map[nums[i]] = 1;
    }
    int max = 0;
    
    for (int i=0;i<MAX_SIZE;++i) {
        int length = 0;
        while (i < MAX_SIZE && map[i]==1) {
            length++;
            i++;
        }
        if (length > max) {
            max = length;
        }
    }
    return max;
}

int main() {
    int a[6] = {100, 4, 200, 1, 3, 2};
    int res = longestConsecutive(a,6);
    return 0;
}
