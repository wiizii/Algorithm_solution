#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10001;
int n;
vector<int> adj[MAX];
int cost[MAX];
int dp[MAX][2];

int solve(int prev, int node, bool stat) {
    int &ret = dp[node][stat];
    if (ret != 0) return ret;
    if (stat) ret += cost[node];
    for (int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if (prev != next) {
            if (stat) {
                ret += solve(node, next, false);
            } else {
                ret += max(solve(node, next, true), solve(node, next, false));
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> cost[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans = max(solve(0, 1, 0), solve(0, 1, 1));
    cout << ans << "\n";
}