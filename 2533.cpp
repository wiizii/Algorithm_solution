#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int n;
vector<int> adj[1000001];
int dp[1000001][2];

int solve(int cur, int stat, int prev) {
    int &ret = dp[cur][stat];
    if (ret) return ret;
    if (adj[cur].size() == 1 && adj[cur][0] == prev) return stat;
    if (stat) {
        ret += 1;
        for (auto next : adj[cur]) {
            if (next == prev) continue;
            ret += min(solve(next, 0, cur), solve(next, 1, cur));
        }
    } else {
        for (auto next : adj[cur]) {
            if (next == prev) continue;
            ret += solve(next, 1, cur);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << min(solve(1, 0, 0), solve(1, 1, 0)) << "\n";
}