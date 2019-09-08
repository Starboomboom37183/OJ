#include <stdio.h>
int num[32];
int reverse(int x){
    if (x == 0) return 0;
    if (x == -2147483648) return 0;
    int flag = 0;
    if (x < 0) {
        flag = 1;
        x = x  * (-1);
    }
    int count = 0;
    while (x > 0) {
        num[count++] = x % 10;
        x = x/10;
    }
    int i = 0;
    long long res = 0;
    while (i < count) {
        long long temp = res * 10;
        res = temp;
        res += num[i];    
        i++;
    }
    
    if (flag) {
        res = res * (-1);
    }
    if (res > 2147483647 || res < -2147483648) {
        return 0;
    }
    return (int)res;  
    
}


int main() {
    int n;
    while (scanf_s("%d", &n)!=EOF) {
        int res = reverse(n);
        printf("%d\n", res);
    }
}