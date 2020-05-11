#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f


vector<pair<int,int> > adj[501];
int n,m;
bool cycle = false;

vector<int> BellmanFord(int start){
    vector<int> dist(n,INF);
    dist[start] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(auto &k : adj[j]){
                if(dist[j] != INF && dist[k.first] > dist[j] + k.second){
                    dist[k.first] = dist[j] + k.second;
                    if(i == (n-1))
                        cycle = true;
                }
            }
        }
    }
    
    return dist;
}

int main(){
    cin >> n >> m;
    n++;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    vector<int> dist = BellmanFord(1);
    if(cycle)
        cout << "-1\n";
    else{
        for(int i=2;i<n;i++){
            if(dist[i] == INF)
                cout << "-1\n";
            else
                cout << dist[i] << "\n";
        }
    }
    return 0;
}
