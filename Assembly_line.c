//2019076708_김이영_12838
#include <stdio.h>
#include <stdlib.h>

int fastest_way(int** a, int **t, int* e, int* x, int n, int** s, int** l, int* S, int* L){
    s[1][1] = e[1] + a[1][1];
    s[2][1] = e[2] + a[2][1];
    
    for(int j = 2; j <= n; j++){
        if(s[1][j-1] <= s[2][j-1] + t[2][j-1]){
            s[1][j] = s[1][j-1] + a[1][j];
            l[1][j] = 1;
        }
        else{
            s[1][j] = s[2][j-1] + t[2][j-1] + a[1][j];
            l[1][j] = 2;
        }
        if(s[2][j-1] <= s[1][j-1] + t[1][j-1]){
            s[2][j] = s[2][j-1] + a[2][j];
            l[2][j] = 2;
        }
        else{
            s[2][j] = s[1][j-1] + t[1][j-1] + a[2][j];
            l[2][j] = 1;
        }
    }
    
    if(s[1][n] + x[1] <= s[2][n] + x[2]){
        *S = s[1][n] + x[1];
        *L = 1;
    }
    else{
        *S = s[2][n] + x[2];
        *L = 2;
    }
    return *S;
}

void print_station(int ** l, int * L, int n){
    int array[n];
    int i = *L;
    array[n] = i;
    for(int j = n; j >= 2; j--){
        i = l[i][j];
        array[j-1] = i;
    }
        
    for(int j = 1; j<= n; j++){
        printf("%d %d\n", array[j], j);
    }
}

int main(){
    int size;
    int e[3];
    int x[3];
    int* S = (int*)malloc(sizeof(int));
    int* L = (int*)malloc(sizeof(int));
    
    scanf("%d", &size);
    
    int* a[3];
    int* t[3];
    
    int* s[3];
    int* l[3];
    
    for(int i = 0; i < 3; i++){
        a[i] = (int*)malloc(sizeof(int*)*(size+1));
        t[i] = (int*)malloc(sizeof(int*)*(size+1));
        s[i] = (int*)malloc(sizeof(int*)*(size));
        l[i] = (int*)malloc(sizeof(int*)*(size+1));
    }
    
    
    for(int i = 0; i < 2; i++){
        scanf("%d", &e[i+1]);
    }
    
    for(int i = 0; i < 2; i++){
        scanf("%d", &x[i+1]);
    }
    
    for(int i = 1; i <= size; i++){
        scanf("%d", &a[1][i]);
    }
    
    for(int i = 1; i <= size; i++){
        scanf("%d", &a[2][i]);
    }
    
    for(int i = 1; i <= size-1; i++){
        scanf("%d", &t[1][i]);
    }
    
    for(int i = 1; i <= size-1; i++){
        scanf("%d", &t[2][i]);
    }
    
    printf("%d\n", fastest_way(a, t, e, x, size, s, l, S, L));
    print_station(l, L, size);
    
    return 0;
}
