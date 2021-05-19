#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int MAX = 501;
const int INF = 0x3f3f3f3f;

set<pii> adj[MAX];
pii trace[MAX];
int n, m, s, e;

vector<int> dijkstra(int n, int start) {
    vector<int> dist(n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [cur_dist, cur] = pq.top();
        pq.pop();
        if (dist[cur] < cur_dist) continue;
        for (auto iter = adj[cur].begin(); iter != adj[cur].end(); iter++) {
            int next = (*iter).first;
            int next_dist = cur_dist + (*iter).second;
            if (next_dist < dist[next]) {
                dist[next] = next_dist;
                trace[next] = {cur, dist[next]};
                pq.push({next_dist, next});
            }
        }
    }
    return dist;
}

void remove_route() {
    int cur = e;
    while (cur != s) {
        pii tmp = trace[cur];
        adj[tmp.first].erase({cur, tmp.second});
        cur = trace[cur].first;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;
        for (int i = 0; i < n; i++) adj[i].clear();
        cin >> s >> e;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].insert({v, w});
        }
        vector<int> dist = dijkstra(n, s);
        int l_route = dist[e];
        remove_route();
        while (true) {
            vector<int> tmp_dist = dijkstra(n, s);
            if (tmp_dist[e] != l_route) break;
            remove_route();
        }
        vector<int> answer = dijkstra(n, s);
        if (answer[e] != INF) {
            cout << answer[e] << "\n";
        } else {
            cout << "-1\n";
        }
    }
}