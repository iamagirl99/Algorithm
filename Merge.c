//2019076708_kimeeyoung_class2
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
  
void merge(int arr[], int p, int q, int r)
{
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    
    int L[n1], R[n2];
  
    for (i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];
    L[n1] = INT_MIN;
    R[n2] = INT_MIN;
    i = 0;
    j = 0;

    for(k = p; k < r + 1; k++){
        if(L[i] >= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        
    }
//  오른쪽 끝났을때
    while (i < n1 && j > n2) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
//  왼쪽 끝났을때
    while (j < n2 && i > n1) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[], int p, int r)
{
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main(){
    int num;
    scanf("%d", &num);
    int arr[num];
    for(int k = 0; k < num; k++){
        scanf("%d", &arr[k]);
    }
    mergeSort(arr, 0, num - 1);
    for(int i = 0; i < num; i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}
