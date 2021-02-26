#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int n;
vector<int> adj[100001];
set<int> s;
queue<int> q;
int order[100001];
bool check[100001];

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
    for (int i = 0; i < n; i++) {
        cin >> order[i];
    }
    if (order[0] != 1) {
        cout << 0 << "\n";
        return 0;
    }
    q.push(1);
    check[1] = true;
    int start = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int cnt = 0;
        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];
            if (!check[next]) {
                check[next] = true;
                s.insert(next);
                cnt++;
            }
        }
        for (int j = start; j < start + cnt; j++) {
            if (!s.count(order[j])) {
                cout << 0 << "\n";
                return 0;
            } else
                q.push(order[j]);
        }
        start += cnt;
    }
    cout << 1 << "\n";
}