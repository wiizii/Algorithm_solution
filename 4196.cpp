#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define MAX 100001
using namespace std;

int v, e;
int id, d[MAX], ans;
bool finished[MAX];
vector<int> adj[MAX];
stack<int> s;

int dfs(int x, vector<vector<int>> &adj) {
    d[x] = ++id;
    s.push(x);
    int parent = d[x];
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i];
        if (!d[y])
            parent = min(parent, dfs(y, adj));
        else if (!finished[y])
            parent = min(parent, d[y]);
    }
    if (parent == d[x]) {
        while (1) {
            int t = s.top();
            s.pop();
            finished[t] = true;
            cout << t << " ";
            if (t == x) break;
        }
        cout << "\n";
        ans++;
    }
    return parent;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> v >> e;
        id = 0, ans = 0;
        memset(d, 0, sizeof(d));
        memset(finished, 0, sizeof(finished));
        vector<vector<int>> adj(v + 1);
        s = {};
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        for (int i = 1; i <= v; i++)
            if (!d[i]) dfs(i, adj);
        cout << ans << "\n";
    }
}
