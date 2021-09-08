//2019076708_김이영_12838
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int matrix_chain_order(int** m, int** s, int* p, int length){
    int n = length - 1;
    for(int i = 1; i<= n; i++){
        m[i][i] = 0;
    }
    
    for(int l = 2; l <= n; l++){
        for(int i = 1; i <= n-l+1; i++){
            int j = i+l-1;
            m[i][j] = INT_MAX;
            for(int k = i; k <= j-1; k++){
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[1][n];
}

void print_paren(int** s, int i, int j){
    if(i==j)
        printf("%d", i);
    else{
        printf("(");
        print_paren(s, i, s[i][j]);
        print_paren(s, s[i][j]+1, j);
        printf(")");
    }
}

int main(){
    int size;
    scanf("%d", &size);
    
    int** m;
    int** s;
    int p[size+1];
    
    m = (int**)malloc(sizeof(int*)*(size+1));
    s = (int**)malloc(sizeof(int*)*(size+1));

    
    for(int i = 0; i< size+1; i++){
        m[i] = (int*)malloc(sizeof(int*)*(size+1));
        s[i] = (int*)malloc(sizeof(int*)*(size+1));
    }
    
    for(int i = 0; i < size+1; i++){
        scanf("%d", &p[i]);
    }
    
    printf("%d\n", matrix_chain_order(m, s, p, size+1));
    print_paren(s, 1, size);
    
    for(int i = 0; i< size+1; i++){
        free(m[i]);
        free(s[i]);
    }
    free(m);
    free(s);
}
