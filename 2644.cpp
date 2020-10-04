#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[101];
bool check[101];

void dfs(int a, int b, int d) {
    if (a == b) {
        cout << d << '\n';
        exit(0);
    }
    for (int i = 0; i < adj[a].size(); i++) {
        int n = adj[a][i];
        if (!check[n]) {
            check[n] = true;
            dfs(n, b, d + 1);
            check[n] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    check[a] = true;
    dfs(a, b, 0);
    cout << -1 << '\n';
    return 0;
}