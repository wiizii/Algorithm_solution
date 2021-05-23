#include <bits/stdc++.h>
using namespace std;

int n;
int tree[51];
vector<int> adj[51];
int dep[51];
int dp[51];

int get_dep(int cur) {
    int ret = 0;
    if (adj[cur].empty()) return 1;
    for (auto next : adj[cur]) ret = max(ret, get_dep(next));
    return ret + 1;
}

int solve(int cur) {
    int &ret = dp[cur];
    if (ret) return ret;
    int w = adj[cur].size();
    int d = 0;
    for (auto next : adj[cur]) d = max(d, dep[next]);
    ret = max(w, d);
    return ret;
}

int main() {
    int answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> tree[i];
    for (int i = 1; i < n; i++) adj[tree[i]].push_back(i);
    for (int i = 0; i < n; i++) dep[i] = get_dep(i);
    cout << solve(0) << "\n";
}