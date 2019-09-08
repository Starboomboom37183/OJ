#include <stdio.h>

int minFlipsMonoIncr(char * S){
    int len = strlen(S);
    int left_zero_count = 0;
    int total_zero_count = 0;
    int left,right;
    for (int i=0;i<len;++i) {
        if (S[i]=='0') {
            total_zero_count++;
        } 
    }
    int min = len;
    for (int i=0;i<len;++i) {
        if (S[i]=='0') {
            left_zero_count++;
            total_zero_count--;
            continue;
        } else if (S[i]=='1') {
            left = i - left_zero_count;
            right = total_zero_count;
            if (min > left + right) {
                min = left + right;
            }

        }
    } 
    left = len - left_zero_count;
    right = total_zero_count;
    if (min > left + right) {
        min = left + right;
    }
    return min;
}

int main() {
    char s[20001] = {0};
    while (scanf("%s", s)!=EOF) {
        int res = minFlipsMonoIncr(s);
        printf("%d\n", res);
    }
    return 0;
}