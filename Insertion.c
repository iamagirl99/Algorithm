//2019076708_kimeeyoung_class2
#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, temp;
    scanf("%d", &num);
    int array[num];
    for(int k = 0; k < num; k++){
        scanf("%d", &temp);
        array[k] = temp;
    }
    int i, j, key;
    for(i = 1; i < num; i++){
        key = array[i];
        for(j = i-1; j >= 0; j--){
            if(array[j] < key){
                array[j+1] = array[j];
            }
            else{
                break;
            }
        }
        array[j+1] = key;
    }
    for(int t = 0; t < num; t++){
        printf("%d\n", array[t]);
    }

    return 0;
}
