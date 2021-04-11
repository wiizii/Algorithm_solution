#include <bits/stdc++.h>
using namespace std;
const int MAX = 102000;

int n, k, m;
vector<int> adj[MAX];
int check[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            adj[x].push_back(n + i);
            adj[n + i].push_back(x);
        }
    }
    queue<int> q;
    q.push(1);
    check[1] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];
            if (!check[next]) {
                if (next <= n)
                    check[next] = check[cur] + 1;
                else
                    check[next] = check[cur];
                if (next == n) {
                    cout << check[next] << "\n";
                    return 0;
                }
                q.push(next);
            }
        }
    }
    cout << -1 << "\n";
}