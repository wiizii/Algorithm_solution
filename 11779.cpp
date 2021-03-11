#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

vector<pair<int, int>> adj[1001];
vector<int> trace(1001, 0);

vector<int> dijkstra(int n, int start) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>> pq;
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
                trace[next] = cur;
                dist[next] = next_dist;
                pq.push({next, -next_dist});
            }
        }
    }
    return dist;
}

vector<int> get_path(int last) {
    vector<int> path;
    while (last) {
        path.push_back(last);
        last = trace[last];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int from, to;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    cin >> from >> to;
    vector<int> dist = dijkstra(n, from);
    cout << dist[to] << "\n";
    vector<int> path = get_path(to);
    cout << path.size() << "\n";
    for (int i : path) {
        cout << i << " ";
    }
}