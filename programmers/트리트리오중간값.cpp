#include <bits/stdc++.h>
#define pii pair<int,int>
#define MAX 250001
using namespace std;

vector<int> adj[MAX];
bool check[MAX];

pii bfs(int node){
    pii ret = {node,0};
   	queue<pii> q;
    q.push({node,0});
   	check[node] = true; 
    while(!q.empty()){
        auto [cur, dist] = q.front();
        q.pop();
        for(int next : adj[cur]){
            if(!check[next]){
               	check[next] = true;
                q.push({next,dist+1});
                if(ret.second < dist+1){
            		ret.first = next;
                    ret.second = dist+1;
                }
            }
        }
    }
	return ret;
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
   	for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pii far = bfs(1);
    memset(check,0,sizeof(check));
    pii so_far = bfs(far.first);
    memset(check,0,sizeof(check));
    check[far.first] = true;
    pii ans1 = bfs(so_far.first);
    memset(check,0,sizeof(check));
    check[so_far.first] = true;
    pii ans2 = bfs(far.first);
    answer = max(ans1.second, ans2.second);
    return answer;
}