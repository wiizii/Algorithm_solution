#include <bits/stdc++.h>
using namespace std;

const int MAX = 100010;

vector<int> adj[MAX];
char c[MAX];
int n;

int solve(int prev, int cur) {
    int ret = 0;
    for (auto &next : adj[cur]) {
        if (next != prev && c[next] == 'R') {
            ret += solve(cur, next);
        }
    }
    return ret + 1;
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
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (c[i] == 'R') continue;
        answer += solve(-1, i) - 1;
    }
    cout << answer << "\n";
}