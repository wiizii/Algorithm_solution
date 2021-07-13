#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;
vector<pii> adj[300001];

vector<int> dijkstra(int n, int start) {
    vector<int> dist(n + 1, INF);
    priority_queue<pii> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cur_dist) continue;
        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i].first;
            int next_dist = cur_dist + adj[cur][i].second;
            if (next_dist < dist[next]) {
                dist[next] = next_dist;
                pq.push({-next_dist, next});
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 1});
    }

    vector<int> dist = dijkstra(n, x);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) ans.push_back(i);
    }
    if (ans.empty())
        cout << -1 << "\n";
    else {
        for (auto i : ans) cout << i << "\n";
    }
}