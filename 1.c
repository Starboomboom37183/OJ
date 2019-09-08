#include <stdio.h>
int dietPlanPerformance(int* calories, int caloriesSize, int k, int lower, int upper){
    int i = 0;
    int T = 0;
    int total = 0;
    while (i < caloriesSize) {
        int j = 0;
        T = 0;
        while ((i+j < caloriesSize) && (j < k)) {
            T += calories[i+j];
            j++;
        }
        if (i +j == caloriesSize) {
            break;
        }
        i++;
        if (T < lower) {
            total-=1;
        } else if (T > upper) {
            total+=1;
        }
    }
    return total;
}

int main() {
    int a[5] = {1,2,3,4,5};
    int k = 1;
    int lower = 3;
    int higher = 3;
    int res = dietPlanPerformance(a,5,1,3,3);
    return 0;
}