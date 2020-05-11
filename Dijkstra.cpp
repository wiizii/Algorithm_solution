#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 987654321;
vector<pair<int,int> > v[801];
int n,e;
int dist[801];

void dijkstra(int start){
    dist[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push({0,start});
    while(!pq.empty()){
        int current = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();
        if(dist[current] < cur_dist) continue;
        for(int i=0;i<v[current].size();i++){
            int next = v[current][i].first;
            int nextDist = cur_dist + v[current][i].second;
            if(nextDist < dist[next]){
                dist[next] = nextDist;
                pq.push({-nextDist,next});
            }
        }
    }
}

int main(){
    int from,to,d;
    int node1, node2;
    for(int i=1;i<=n;i++){
        dist[i] = INF;
    }
    cin >> n >> e;
    for(int i=0;i<e;i++){
        cin >> from >> to >> d;
        v[from].push_back({to,d});
    }
    cin >> node1 >> node2;
    
}
