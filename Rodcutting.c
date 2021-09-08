//2019076708_김이영_12838
#include<stdio.h>
#include<limits.h>
#include <stdlib.h>
 
void cutRod(int price[], int n)
{
    int s[n + 1];
    int val[n + 1];
    val[0] = 0;
    int i, j;
    for (j = 1; j <= n; j++){
       int max_val = -1;
        for (i = 1; i <= j; i++){
            if(max_val < price[i] + val[j - i]){
                max_val = price[i] + val[j - i];
                s[j] = i;
            }
        }
        val[j] = max_val;
   }
    printf("%d\n", val[n]);
    while(n > 0){
        printf("%d ", s[n]);
        n = n - s[n];
    }
}

int main()
{
    int size;
    scanf("%d", &size);
    int array[size + 1];
    for(int i = 1; i <= size; i++){
        scanf("%d", &array[i]);
    }
    cutRod(array, size);
    return 0;
}
