//2019076708_김이영_12838
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS


int bit_index = 0;

struct MinHeapNode {
    int freq;
    struct MinHeapNode *left, *right;
};

struct MinHeap {
    int size;
    int capacity;
    struct MinHeapNode** array;
};


struct MinHeapNode* newNode(int freq)
{
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));

    temp->left = temp->right = NULL;
    temp->freq = freq;

    return temp;
}


struct MinHeap* createMinHeap(int capacity){

    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));

    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}


void swapMinHeapNode(struct MinHeapNode** a,struct MinHeapNode** b){

    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx){

    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}


int isSizeOne(struct MinHeap* minHeap)
{
    return (minHeap->size == 1);
}


struct MinHeapNode* extractMin(struct MinHeap* minHeap){

    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --(minHeap->size);
    minHeapify(minHeap, 0);

    return temp;
}

void insertMinHeap(struct MinHeap* minHeap,struct MinHeapNode* minHeapNode){

    ++(minHeap->size);
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {

        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}


void buildMinHeap(struct MinHeap* minHeap){

    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i){
        minHeapify(minHeap, i);
        
    }
}


void printArr(int arr[], int n, int* code)
{
    int i;
    int count = 0;
    for (i = 0; i < n; ++i){
        count++;
    }
    code[bit_index] = count;
}


int isLeaf(struct MinHeapNode* root){

    return !(root->left) && !(root->right);
}


struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size){

    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}


struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size){
    
    struct MinHeapNode *left, *right, *top;

    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) {

        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode(left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}


void printCodes(struct MinHeapNode* root, int arr[], int top, int* code){

    if (root->left) {

        arr[top] = 0;
        printCodes(root->left, arr, top + 1, code);
    }

    if (root->right) {

        arr[top] = 1;
        printCodes(root->right, arr, top + 1, code);
    }

   
    if (isLeaf(root)) {

        printArr(arr, top, code);
        code[bit_index] = code[bit_index] * (root->freq);
        bit_index++;
        
    }
}


void HuffmanCodes(char data[], int freq[], int size, int* code){

    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    int arr[30000], top = 0;
    printCodes(root, arr, top, code);
    
}


int main()
{
    int sum = 0;
    int q = 0;
    int size = 0;
    int total_num = 0;
    
    scanf("%d", &size);
    //fflush(stdin);
    
    char alphabet[4];
    
    //char* arr = (char*)calloc(sizeof(char), size);
    //int* freq = (int*)malloc(sizeof(int) * size);
    char arr[30000] = {0};
    int freq[30000] = {0};

    for(int i = 0;  i < size; i++){
        scanf("%s", alphabet);
        scanf("%d", &freq[i]);
        //arr[i] = alphabet;
//        fflush(stdin);
    }
    scanf("%d", &total_num);
    
    
    //char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//    int freq[] = { 45000, 13000, 12000, 16000, 9000, 5000 };
//
//    int size = sizeof(arr) / sizeof(arr[0]);
    //int* code = (int*)malloc(sizeof(int) * size);
    int code[30000] = {0};
    
    int s = size;
    while(s != 0){
        s = s / 2;
        q++;
    }
    
    printf("%d\n", (q * total_num));


    HuffmanCodes(arr, freq, size, code);
    
    for(int i = 0; i < size; i++){
        sum += code[i];
    }
    
    printf("%d\n", sum);

    return 0;
}
