#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<pair<int,int>> adj[1001];
int sets[1001];
int N, M;


int main(){
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    priority_queue<pair<int,int>> pq;
    sets[1] = 1;
    for(int i=0;i<adj[1].size();i++)
        pq.push({-adj[1][i].second, adj[1][i].first});
    int ans = 0;
    pair<int,int> from, to;
    while(!pq.empty()){
        from = pq.top();
        pq.pop();
        if(sets[from.second])
            continue;
        sets[from.second] = 1;
        ans -= from.first;
        
        for(int i=0;i<adj[from.second].size();i++){
            to = adj[from.second][i];
            if(sets[to.first])
                continue;
            pq.push({-to.second, to.first});
        }
    }
    cout << ans << "\n";
}
