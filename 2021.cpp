#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int MAX = 200010;
int n, l;
int start, last;
vector<int> adj[MAX];
bool check[MAX];

int bfs() {
    queue<pii> q;
    q.push({start, 0});
    check[start] = true;
    while (!q.empty()) {
        auto [cur, cnt] = q.front();
        q.pop();
        if (cur == last) return cnt - 1;
        for (auto next : adj[cur]) {
            if (!check[next]) {
                check[next] = true;
                if (next > n)
                    q.push({next, cnt});
                else
                    q.push({next, cnt + 1});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l;
    for (int i = 1; i <= l; i++) {
        while (1) {
            int x;
            cin >> x;
            if (x == -1) break;
            adj[n + i].push_back(x);
            adj[x].push_back(n + i);
        }
    }
    cin >> start >> last;
    if (start == last) {
        cout << 0 << "\n";
        return 0;
    }
    cout << bfs() << "\n";
}