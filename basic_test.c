// basic test
#include <stdio.h>  
#define max(a,b) ((a)>(b)?(a):(b))  
  
  
  
int main(){  
      
    int v = 10 ;    
    int n = 5 ;      
       
    int value[] = {0, 8 , 10 , 4 , 5 , 5};       
    int weight[] = {0, 6 , 4 , 2 , 4 , 3};     
    int i,j;      
    int dp[n+1][v+1];  
    for(i = 0; i < n+1; i++)  
        for(j = 0; j < v+1; j++)  
            dp[i][j] = 0;  
  
  
    for(i = 1; i <= n; i++){  
        for(j = 1; j <= v; j++){  
            if(j >= weight[i])  
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]] + value[i]);  
            else  
                dp[i][j] = dp[i-1][j];  
        }  
    }  
  
    printf("%d",dp[n][v]); 
    return 0;
}