//2019076708_kimeeyoung_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;

int visited[1000];
int graph[1000][1000];
stack<int> s;
int node, edge, cycle;

void DFS(int ver) {
    visited[ver] = 1;
    for (int i = 1; i <= node; i++) {
        if (graph[ver][i]) {
            //재방문
            if (visited[i] == 1) {
                cycle = 1;
                printf("0\n");
                return;
            }
            //빠꾸
            
            else if (visited[i] == 2){
                continue;
            }
            
            else{
                DFS(i);
            }
        }
    }
    s.push(ver);
    visited[ver] = 2;
}

int main(void) {
    scanf("%d %d", &node, &edge);
    
    for (int i = 1; i <= edge; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
    }
    
    for (int i = 1; i <= node; i++) {
        if (!visited[i]){
            DFS(i);
        }
    }
    
    if (cycle){
        return 0;
    }
    
    printf("1\n");
    while (!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }
}

