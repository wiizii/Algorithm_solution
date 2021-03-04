#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int r[501];
int adj[501][501];
int ind[501][501];

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(r, 0, sizeof(r));
        memset(adj, 0, sizeof(adj));
        memset(ind, 0, sizeof(ind));
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> r[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ind[r[j]][r[i]] = true;
            }
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; i) {
            int u, v;
            cin >> u >> v;
            adj[u][v] = false;
        
        }
    }
}