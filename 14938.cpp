#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int, int>
using namespace std;

const int INF = 0x3f3f3f3f;
vector<pii> adj[101];
vector<int> item(101, 0);

vector<int> dijkstra(int n, int start) {
    vector<int> dist(n + 1, INF);
    priority_queue<pii> pq;
    dist[start] = 0;
    pq.push({start, 0});
    while (!pq.empty()) {
        int cur = pq.top().first;
        int cur_dist = -pq.top().second;
        pq.pop();
        if (dist[cur] < cur_dist) continue;
        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i].first;
            int next_dist = cur_dist + adj[cur][i].second;
            if (next_dist < dist[next]) {
                dist[next] = next_dist;
                pq.push({next, -next_dist});
            }
        }
    }
    return dist;
}

int main() {
    int ans = 0;
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) cin >> item[i];
    for (int i = 0; i < r; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> dist[101];
    for (int i = 1; i <= n; i++) dist[i] = dijkstra(n, i);
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = 0; j < dist[i].size(); j++)
            if (dist[i][j] != INF && dist[i][j] <= m) tmp += item[j];
        ans = max(ans, tmp);
    }
    cout << ans << "\n";
}