// 两点法-尺取法
#include <stdio.h>

void twoPoint(int a[], int len, int S) {
    int start = 0;
    int end = 0;
    int sum = 0;
    while (1) {
        while (end < len && sum < S) {
            sum += a[end];
            end++;
        }
        if (sum < S) break;
        else if (sum == S) {
            printf("%d %d\n", start, end-1);
            sum += a[end];
            end++;
        } else {
            sum -= a[start];
            start++;
        }
    }
}

int main() {
    int x[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    twoPoint(x, 14, 15);
    return 0;
}