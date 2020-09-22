#include <iostream>
#include <vector>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

struct Edge {
    int from, to, cost;
    Edge(int f = 0, int t = 0, int c = 0) : from(f), to(t), cost(c) {}
};
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<ll> dist(n + 1, INF);
    vector<Edge> p;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        p.push_back(Edge(u, v, w));
    }
    dist[1] = 0;
    bool cycle = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int now = p[j].from;
            int next = p[j].to;
            int ncost = p[j].cost;
            if (dist[now] != INF && dist[next] > dist[now] + ncost) {
                dist[next] = dist[now] + ncost;
                if (i == n) {
                    cycle = true;
                    break;
                }
            }
        }
    }
    if (cycle) {
        cout << -1 << "\n";
    } else {
        for (int i = 2; i <= n; i++) {
            if (dist[i] != INF)
                cout << dist[i] << '\n';
            else
                cout << -1 << '\n';
        }
    }
    return 0;
}