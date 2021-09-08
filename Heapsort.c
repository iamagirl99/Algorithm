//2019076708_kimeeyoung_class2
#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* A, int index, int heap_size){
    int left, right, smallest;
    left = 2 * index + 1;
    right = 2 * index + 2;
    smallest = index;

    if(left < heap_size && A[left] < A[smallest]){
        smallest = left;
    }
    if(right < heap_size && A[right] < A[smallest]){
        smallest = right;
    }
    if(smallest != index){
        swap(&A[index], &A[smallest]);
        heapify(A, smallest, heap_size);
    }
}

void build_heap(int* A, int heap_size){
    for(int i = heap_size / 2 - 1; i >= 0; i--){
        heapify(A, i, heap_size);
    }
}

void heap_sort(int* A, int heap_size){
    build_heap(A, heap_size);
    for(int i = heap_size - 1; i >= 0; i--){
        swap(&A[0], &A[i]);
        heapify(A, 0, i);
    }
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    heap_sort(A, n);
    for(int i = 0; i < k; i++){
        printf("%d\t", A[i]);
    }
    printf("\n");
    for(int i = k; i < n; i++){
        printf("%d\t", A[i]);
    }

    return 0;
}
