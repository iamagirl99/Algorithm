//2019076708_kimeeyoung_12838
#include <stdio.h>
#include <stdlib.h>

int Time = 0;
int count = 0;

typedef struct Node* node;
struct Node{
    int number;
    int color;
    int start_time;
    int finish_time;
    struct Node* pie;
    struct Node* next;
};


void add_node(node old, int num){
    if(old ->next == NULL){
        node newNode = (node)malloc(sizeof(struct Node));
        old->next = newNode;
        newNode->next = NULL;
        newNode->number = num;
    }
    else{
        add_node(old->next, num);
    }
}

void delete_node(node old, int num){
    node before = old;
    while(1){
        if(before->next->number == num){
            before->next = before->next->next;
            break;
        }
        else before = before->next;
    }
}

void DFS_look(node* nodes, int length, node n){
    n->color = 1;
    Time++;
    n->start_time = Time;
    node temp = n;
    while(temp->next != NULL){
        node temp2 = nodes[(temp->next->number)-1];
        if(temp2->color == 0){
            temp2->pie = n;
            delete_node(temp2, n->number);
            DFS_look(nodes, length, temp2);
        }
        temp = temp->next;
    }
    Time++;
    n->finish_time = Time;
    n->color = 2;
}

void DFS(node* nodes, int length){
    for(int i = 0; i<length; i++){
        if(nodes[i]->color == 0)
            count++;
            DFS_look(nodes, length, nodes[i]);
    }
}


int main(void) {
    int vertax;
    int edge;

    scanf("%d %d", &vertax, &edge);
    node nodes[vertax];
    for(int i = 0; i<vertax; i++){
        node newNode = (node)malloc(sizeof(struct Node));
        nodes[i] = newNode;
        nodes[i]->number = i+1;
        nodes[i]->color = 0;
        nodes[i]->next = NULL;
    }

    int a, b;


    for(int i = 0; i< edge; i++){
        scanf("%d %d", &a, &b);

        add_node(nodes[a-1], b);
        add_node(nodes[b-1], a);
    }

    DFS(nodes, vertax);

    printf("%d", count);
    return 0;
}
