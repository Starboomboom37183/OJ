#include <stdio.h>
int rangeBitwiseAnd(int m, int n){
    if (m == 0 || n==0) return 0;
    int offset = 31;
    int start = 0;
    while (offset >= 0) {
        if ((n >> offset)&1) {
            start = offset;
            break;
        }
        offset--;
    }
    int count = 0;
    while (offset >=0 && ((m>>offset) & 1) == ((n >> offset) &1 )) {
        count++;
        offset--;
    }

    int res = 0;
    while (count > 0) {
        if ((n>>start)&1) {
            res += (1 << start);
        }
        start--;
        count--;
    }

    return res;

}

int main() {
    int m, n;
    while (scanf_s("%d %d", &m, &n) !=EOF) {  
        int res = rangeBitwiseAnd(m,n);
        printf("%d\n", res);
    }
    return 0;
}