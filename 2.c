#include <stdio.h>
#include <math.h>
#define MOD 1000000007
int isPrime(n) {
    if (n==1) return 0;
    if (n==2) return 1;
    for (int i=2;i<=sqrt(n);++i) {
        if (n % i ==0) {
            return 0;
        }
    }
    return 1;
}

int get_PrimeNo(int n) {
    int count = 0;
    for (int i=1;i<=n;++i) {
        if (isPrime(i)) {
            count++;
        }
    }
    return count;
}

long long Component(int n) {
    long long result = 1;
    for (int i = 1;i<=n;++i) {
        result = result * i ;
        result = result % MOD;
    }
    return result % MOD ;
}

int numPrimeArrangements(int n) {
    int count = get_PrimeNo(n);
    int  res =(Component(count) * Component(n - count)) % MOD ;
    return res;
}
int main() {
    int n;
    scanf("%d", &n);
    int res = numPrimeArrangements(n);
    return 0;
}
