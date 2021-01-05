#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int k, v, e;
vector<int> adj[20001];
int color[20001];

void dfs(int n, int c) {
    color[n] = c;
    for (int i = 0; i < adj[n].size(); i++) {
        int next = adj[n][i];
        if (!color[next]) dfs(next, 3 - c);
    }
}

bool isBipartite() {
    for (int i = 1; i < v; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            int next = adj[i][j];
            if (color[i] == color[next]) return false;
        }
    }
    return true;
}

int main() {
    cin >> k;
    while (k--) {
        for (int i = 1; i <= 20000; i++) adj[i].clear();
        memset(color, 0, sizeof(color));

        cin >> v >> e;

        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int j = 1; j <= v; j++)
            if (color[j] == 0) dfs(j, 1);
        if (isBipartite())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}