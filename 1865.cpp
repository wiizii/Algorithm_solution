#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, w;
        cin >> n >> m >> w;
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> dist(n + 1, INF);
        for (int i = 0; i < m; i++) {
            int u, v, cost;
            cin >> u >> v >> cost;
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
        }
        for (int i = 0; i < w; i++) {
            int u, v, cost;
            cin >> u >> v >> cost;
            adj[u].push_back({v, -cost});
        }
        dist[1] = 0;
        bool cycle = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (auto next : adj[j]) {
                    int from = j;
                    int to = next.first;
                    int cost = next.second;
                    if (dist[from] + cost < dist[to]) {
                        dist[to] = dist[from] + cost;
                        if (i == n) {
                            cycle = true;
                            break;
                        }
                    }
                }
            }
        }
        if (cycle)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}