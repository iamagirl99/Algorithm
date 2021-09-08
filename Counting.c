//2019076708_kimeeyoung_class2
#include <stdio.h>

int main() {
    int num = 0;
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    int A[k], B[k];
    for(int i = 0; i < k; i++){
        scanf("%d %d", &A[i], &B[i]);
    }

    int Key[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &Key[i]);
    }

    int Count[k];
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            if(A[i] <= Key[j] && Key[j] <= B[i]){
                num++;
            }
        }
        Count[i] = num;
        num = 0;
    }
    for(int i = 0; i < k; i++){
        printf("%d\n", Count[i]);
    }

    return 0;
}


