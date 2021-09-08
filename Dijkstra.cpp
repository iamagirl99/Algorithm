//2019076708_kimeeyoung_12838
#include<iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
 
int main()
{
    int V,E;
    scanf("%d %d", &V ,&E);
    int start = 1;
    vector<pair<int,int> > arr[V+1];
    for(int i=0;i<E;i++){
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        arr[x].push_back({y, w});
    }
    int dist[V+1];
    fill(dist,dist+V+1,INT_MAX);
    priority_queue<pair<int,int> > qu;
    
    qu.push({0,start});
    dist[start]=0;
    
    while(!qu.empty()){
        int cost = -qu.top().first;
        int here = qu.top().second;
        
        qu.pop();
            
        for(int i=0; i<arr[here].size(); i++){
            int next = arr[here][i].first;
            int nextcost = arr[here][i].second;
            
            if(dist[next] > dist[here] + nextcost){
                
                dist[next]=dist[here]+nextcost;
                qu.push({-dist[next],next});
            }
        }
        
    }
    int max = 0;
    for(int i=1;i<=V;i++){
        if(max < dist[i]){
            max = dist[i];
        }
       
    }
    printf("%d", max);
}
