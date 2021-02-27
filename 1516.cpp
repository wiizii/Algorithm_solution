#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int n;
vector<int> adj[501];
int ind[501];
int t[501];
int dp[501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        while (1) {
            int x;
            cin >> x;
            if (x == -1) break;
            adj[x].push_back(i);
            ind[i]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(i);
            dp[i] = t[i];
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < adj[x].size(); i++) {
            int cur = adj[x][i];
            if (ind[cur] != 0) {
                ind[cur]--;
                if (ind[cur] == 0) {
                    q.push(cur);
                }
                dp[cur] = max(dp[cur], dp[x] + t[cur]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << "\n";
    }
}