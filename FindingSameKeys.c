//2019076708_kimeeyoung_class2
#include <stdio.h>

int main() {
    int n, m;
    int count = 0;
    scanf("%d %d", &n, &m);
    int A[n], B[m];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &B[i]);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i] == B[j]){
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}
