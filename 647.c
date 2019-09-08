#include <stdio.h>
// 回文子串
int countSubstrings(char * s){
    int len = strlen(s);
    int count  = 0;
    for (int j = 0;j < len;++j) {
        for (int i = 0;i<=j;++i) {
            if (i == j) dp[i][j] = true;
            else if (i == j-1) {
                dp[i][j] = (s[i] == s[j]);
            } else {
                dp[i][j] = ((s[i] == s[j]) && dp[i+1][j-1]);
            }
            if (dp[i][j]) {
                count++;
            }
        }
    }
    return count;
}
int main() {
    return 0;
}