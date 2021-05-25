#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAX = 100001;
const int MOD = 1000000007;
int n;
vector<pii> adj[MAX];
ll acc = 0;

ll solve(int prev, int cur) {
    ll ret = 1;
    for (auto i : adj[cur]) {
        auto [next, cost] = i;
        if (prev == next) continue;
        ll tmp = (solve(cur, next) * cost) % MOD;
        acc = (acc + ret * tmp) % MOD;
        ret = (ret + tmp) % MOD;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    solve(-1, 1);
    cout << acc << "\n";
}