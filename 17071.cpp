#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int MAX = 500001;

int n, k;
int check[MAX][2];
int trace[MAX];
queue<pii> q;

int main() {
    memset(check, -1, sizeof(check));
    memset(trace, -1, sizeof(trace));
    cin >> n >> k;
    for (int i = 0, w = 1; k < MAX; i++, w++) {
        trace[k] = i;
        k += w;
    }
    q.push({n, 0});
    check[n][0] = 0;
    while (!q.empty()) {
        auto [x, t] = q.front();
        int o = t % 2;
        q.pop();
        if (x + 1 < MAX && check[x + 1][!o] == -1) {
            check[x + 1][!o] = check[x][o] + 1;
            q.push({x + 1, t + 1});
        }
        if (x - 1 >= 0 && check[x - 1][!o] == -1) {
            check[x - 1][!o] = check[x][o] + 1;
            q.push({x - 1, t + 1});
        }
        if (x * 2 < MAX && check[x * 2][!o] == -1) {
            check[x * 2][!o] = check[x][o] + 1;
            q.push({x * 2, t + 1});
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < MAX; i++) {
        if (trace[i] != -1) {
            int k = trace[i] % 2;
            if (check[i][k] != -1 && check[i][k] <= trace[i])
                ans = min(ans, trace[i]);
        }
    }
    if (ans == 0x3f3f3f3f)
        cout << "-1\n";
    else
        cout << ans << "\n";
    return 0;
}