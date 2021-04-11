#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;

int n, k, m;
vector<int> adj[MAX];
vector<int> hyper[1001];
int check[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            adj[x].push_back(i);
            hyper[i].push_back(x);
        }
    }
    queue<int> q;
    q.push(1);
    check[1] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++) {
            for (int j = 0; j < hyper[adj[cur][i]].size(); j++) {
                int next = hyper[adj[cur][i]][j];
                if (!check[next]) {
                    check[next] = check[cur] + 1;
                    if (next == n) {
                        cout << check[next] << "\n";
                        return 0;
                    }
                    q.push(next);
                }
            }
        }
    }
    cout << -1 << "\n";
}