//2019076708_kimeeyoung_12838
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, pair<int, int> > pp;

int V;
int E;
priority_queue < pp, vector<pp>, greater<pp> > input;
vector<pp> output;

int root[500];

int find_parent(int x) {
    if (root[x] == x) {
        return x;
    }
    root[x] = find_parent(root[x]);
    return root[x] = find_parent(root[x]);
}

void Union(int x, int y) {
    root[find_parent(x)] = find_parent(y);
}

int main() {
    
    scanf("%d %d", &V, &E);
    
    for (int i = 1; i <= V; i++) {
        root[i] = i;
    }
    for (int i = 1; i <= E; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        
        input.push(make_pair(w, make_pair(x, y)));
    }
    
    while (!input.empty()) {
        int a = input.top().second.first;
        int b = input.top().second.second;
        
        if (find_parent(a) == find_parent(b)) {
            input.pop();
        }
        else {
            Union(a, b);
            output.push_back(input.top());
            input.pop();
        }
    }
    
    printf("%d\n", output.size());
    
    for(int i = 0; i<output.size(); i++) {
        printf("%d %d %d\n", output[i].second.first, output[i].second.second, output[i].first);
    }
}
