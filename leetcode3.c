// leetcode 第三题 ，无重复的最大子串
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lengthOfLongestSubstring(char * s){
    if (s==NULL) return 0;
    int len = strlen(s);
    int begin = 0;
    int end = 0;
    int max = 0 ;
    int cur_len = 0;
    int c[256] = {0};
    while (end < len) {
        if (c[s[end]]==0) {
            c[s[end]] = 1;
        } else {
            if (max < end - begin) {
                max = end - begin;
            } 
            while (s[begin] != s[end]) {
                c[s[begin]] = 0;
                begin++;
            }
            begin++;
        }
        end++;
    }

    if (max < end - begin) {
        max = end - begin;
    }
    return max;


}
int main() {
    char s[100] = "b";
    // while (1) {
        printf("%s\n", s);
        int res = lengthOfLongestSubstring(s);
        printf("%d\n", res);
    // }
    return 0;
}
