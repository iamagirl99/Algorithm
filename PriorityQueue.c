//2019076708_kimeeyoung_class2
#include <stdio.h>
#include <stdlib.h>

typedef struct Heapstruct heap;

struct Heapstruct {
    int size;
    int* arr;
};

heap* CreateHeap(int size_) {
    heap* tmp;
    tmp = (heap*)malloc(sizeof(heap));
    tmp->size = 0;
    tmp->arr = (int*)malloc(sizeof(int) * (size_ + 1));

    return tmp;
}

void max_heapify(heap* heap, int k) {
    int child = k * 2;
    int tmp_;
    if (heap->size >= child) {
        if (child != heap->size && heap->arr[child] <= heap->arr[child + 1]){
            child++;
        }
        if (heap->arr[child] > heap->arr[k]) {
            tmp_ = heap->arr[k];
            heap->arr[k] = heap->arr[child];
            heap->arr[child] = tmp_;
            max_heapify(heap, child);
        }
    }

}

void Insert(heap* h, int value) {
    int i;
    for (i = ++h->size; i / 2 > 0 && h->arr[i / 2] < value; i /= 2) {
        h->arr[i] = h->arr[i / 2];
    }
    h->arr[i] = value;
}

int DeleteMax(heap* h) {
    int i, child, max, end;
    max = h->arr[1];
    end = h->arr[h->size--];

    for (i = 1; i * 2 <= h->size; i = child) {
        child = i * 2;
        if (child != h->size && h->arr[child] <= h->arr[child + 1]){
            child++;
        }
        if (end < h->arr[child]){
            h->arr[i] = h->arr[child];
        }
        else
            break;
    }
    h->arr[i] = end;
    return max;
}

int main() {
    heap* maxheap = CreateHeap(100000);
    int* m_arr = (int*)malloc(sizeof(int) * 100000);
    int cnt = 0;
    while (1) {
        int choice, num, c_idx;
        scanf("%d", &choice);
        if (choice == 0) {
            for (int j = 0; j < cnt; ++j){
                printf("%d ", m_arr[j]);
            }
            printf("\n");
            for (int j = 1; j <= maxheap->size; ++j){
                printf("%d ", maxheap->arr[j]);
            }
            printf("\n");
            break;
        }
        
        else if (choice == 1) {
            scanf("%d", &num);
            Insert(maxheap, num);
        }
        
        else if (choice == 2) {
            m_arr[cnt++] = DeleteMax(maxheap);
        }
        
        else if (choice == 3) {
            scanf("%d %d", &c_idx, &num);
            maxheap->arr[c_idx] = num;
            for (int j = c_idx; j > 0; j /= 2){
                max_heapify(maxheap, j);
            }
        }
    }
    return 0;
}
