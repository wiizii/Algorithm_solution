#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;

vector<int> adj[MAX];
int n;
int w[MAX];
int dp[MAX][2];
vector<int> t;

int solve(int prev, int cur, bool s) {
    int &ret = dp[cur][s];
    if (ret) return ret;
    if (s) ret += w[cur];
    for (auto &next : adj[cur]) {
        if (prev == next) continue;
        if (s)
            ret += solve(cur, next, false);
        else
            ret += max(solve(cur, next, true), solve(cur, next, false));
    }
    return ret;
}

void trace(int prev, int cur, bool s) {
    if (s) {
        t.push_back(cur);
        for (auto &next : adj[cur]) {
            if (prev == next) continue;
            trace(cur, next, false);
        }
    } else {
        for (auto &next : adj[cur]) {
            if (prev == next) continue;
            if (dp[next][true] >= dp[next][0])
                trace(cur, next, true);
            else
                trace(cur, next, false);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans1 = solve(-1, 1, true);
    int ans2 = solve(-1, 1, false);
    if (ans1 >= ans2)
        trace(-1, 1, true);
    else
        trace(-1, 1, false);
    sort(t.begin(), t.end());
    cout << max(ans1, ans2) << "\n";
    for (auto i : t) cout << i << " ";
    return 0;
}