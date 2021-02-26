#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int n;
set<int> adj[100001];
bool check[100001];
int order[100001];
int cnt = 0;
int ans = 1;

void dfs(int x) {
    if (check[x]) return;
    check[x] = true;
    cnt++;
    int next = order[cnt];
    if (adj[x].count(next) && !check[next]) {
        dfs(next);
    } else if (adj[x].size() == 1) {
        return;
    } else {
        ans = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (int i = 0; i < n; i++) {
        cin >> order[i];
    }
    if (order[0] != 1) {
        cout << 0 << "\n";
        return 0;
    }
    dfs(1);
    cout << ans << "\n";
}