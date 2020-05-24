#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
vector<pair<int,pair<int,int>>> adj;

struct DisjointSet{
    vector<int> parent, rank;
    DisjointSet(int n): parent(n), rank(n,1){
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

int kruskal(){
    int ret = 0;
    DisjointSet sets(m);
    sort(adj.begin(), adj.end());
    for(int i=0;i<adj.size();i++){
        int cost = adj[i].first;
        int u = adj[i].second.first;
        int v = adj[i].second.second;
        if(sets.find(u) == sets.find(v))
            continue;
        sets.merge(u,v);
        ret += cost;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        adj.clear();
        int sum = 0;
        cin >> m >> n;
        if(m == 0 && n == 0)
            break;
        for(int i=0;i<n;i++){
            int x,y,z;
            cin >> x >> y >> z;
            adj.push_back({z,{x,y}});
            sum+=z;
        }
        cout << sum-kruskal() << "\n";
    }
    return 0;
}

