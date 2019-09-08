#include <stdio.h>
#define MAX(a,b) ((a)>(b) ? (a):(b))
int candy(int* ratings, int ratingsSize){
    if (ratingsSize==1) return 1;
    int *temp = (int *)malloc(ratingsSize * sizeof(int));
    for (int i=0;i<ratingsSize;++i) {
        temp[i] = 1;
    }
    for (int i = 1;i < ratingsSize;++i) {
        if (ratings[i] > ratings[i-1]) {
            temp[i] = temp[i-1] + 1;
        }
    }

    for (int i = ratingsSize-2;i>=0;--i) {
        if (ratings[i] > ratings[i+1]) {
            temp[i] = MAX(temp[i+1]+1, temp[i]);
        }
    }
    int sum = 0;
    for (int i=0;i<ratingsSize;++i) {
        sum += temp[i];
    }
    return sum;
}
int main () {
    int a[3] = {1,2,2};
    int res = candy(a,3);
    printf("%d\n", res);
    return 0;
}