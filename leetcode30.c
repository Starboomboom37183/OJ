bool isCovered(int map[], int tmap[]) {
    for (int i=0; i < 26;++i) {
        if (map[i] > 0 && tmap[i] == 1) {
            return false;
        }
    }
    return true;
}

int* findSubstring(char * s, char **words, int wordsSize, int* returnSize){
    if (wordsSize==0) {
        *returnSize = 0;
        return NULL;
    }
    int map[26] = {0};
    int tmap[26] = {0};
    int count = 0;
    for (int i = 0;i < wordsSize;++i) {
        for (int j = 0;j < strlen(words[i]);++j) { 
            map[words[i][j] - 'a']++;
            tmap[words[i][j] - 'a'] = 1;
            count++;
        }
    }
    int len = strlen(s);
    int *res  = malloc(sizeof(int) * len);
    int start = 0;
    int end = 0;
    int cnt = 0;
    while (1) {
        while (end < len && !isCovered(map, tmap)) {
            map[s[end] - 'a']--;
            end++;
        }
        if (!isCovered(map, tmap)) {
            if (start == 0) 
            {
                *returnSize = 0;
                return NULL; 
            }
            break;
        }
        else {
            if (end - start==count) {
                char *temp = malloc(sizeof(char) * (count+1));
                for (int i =0; i < count;++i) {
                    temp[i] = s[start + i];
                }
                temp[count] = '\0';
                int i = 0;
                int j = 0;
                int wordLen = strlen(wordss[0]);
                int visited[wordSize];
                memset(visited, 0, wordsSize);
                while(i < count) {
                    for (j = 0;j < wordsSize;++j) {
                        if (visited[j]==0 && strncmp(temp+i, words[j], wordLen)==0) {
                            i = i + wordLen;
                            visited[j] = 1;
                            break;
                        }
                    }
                    if (j==wordSize) {
                        *returnSize = 0;
                        return NULL;
                    }
                    
                }
                if (i==count) {
                    res[cnt++] = start;
                }

            }
            map[s[start] - 'a']++;
            start++;
    }
}
    *returnSize = cnt;
    return res;
}