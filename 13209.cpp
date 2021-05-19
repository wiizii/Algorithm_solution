#include <bits/stdc++.h>
#define ll long long
using namespace std;
using plli = pair<ll, int>;

const int MAX = 100001;

vector<int> adj[MAX];
int n, k;
bool check[MAX];
ll p[MAX];

ll dfs(int cur, ll &m, int &t) {
    ll acc = 0;
    check[cur] = true;
    priority_queue<ll> pq;

    for (int &next : adj[cur]) {
        if (check[next]) continue;
        ll sum = dfs(next, m, t);
        acc += sum;
        pq.push(sum);
    }

    while (!pq.empty() && acc + p[cur] > m) {
        t++;
        acc -= pq.top();
        pq.pop();
    }
    return acc + p[cur];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll answer = 0;
        ll l = 0, r = 0, mid;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            r += p[i];
            l = max(l, p[i]);
        }
        int u, v;
        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        while (l <= r) {
            mid = (l + r) / 2;
            memset(check, 0, sizeof(check));
            int result = 0;
            dfs(1, mid, result);
            if (result <= k) {
                answer = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << answer << "\n";
    }
}