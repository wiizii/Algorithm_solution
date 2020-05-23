#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int V,E;

vector<pair<int,pair<int,int> > > adj;

struct DisjointSet{
    vector<int> parent, rank;
    DisjointSet(int n): parent(n),rank(n,1){
        for(int i=0;i<n;i++)
            parent[i] = i;
        }
        int find(int u){
            if(u == parent[u])
                return u;
            return parent[u] = find(parent[u]);
        }

        void merge(int u, int v){
            u = find(u); v = find(v);
            if(u == v)
                return;
            if(rank[u] > rank[v])
                swap(u,v);
            parent[u] = v;
            if(rank[u] == rank[v])
                rank[v]++;
        }

};

int kruskal() {
    int ret = 0;
    int last = 0;
    DisjointSet sets(V);
    sort(adj.begin(), adj.end());
    for (int i = 0; i < E; i++) {
        int cost = adj[i].first;
        int u = adj[i].second.first;
        int v = adj[i].second.second;
        if (sets.find(u) == sets.find(v))
            continue;
        sets.merge(u, v);
        ret += cost;
        last = cost;
    }
    return ret-last;
}

int main(){
    cin >> V >> E;
    V++;
    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj.push_back(make_pair(w,make_pair(u,v)));
    }
    
    cout << kruskal() << "\n";
}

