#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
vector<int> check(101, INF);
map<int, int> mp;

int main() {
    int ans = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + m; i++) {
        int u, v;
        cin >> u >> v;
        mp[u] = v;
    }
    queue<int> q;
    q.push(1);
    check[1] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == 100) {
            cout << check[cur] << "\n";
            break;
        }
        for (int i = 1; i <= 6; i++) {
            int next = cur + i;
            if (next > 100) continue;
            if (mp.count(next)) next = mp[next];
            if (check[cur] + 1 < check[next]) {
                check[next] = check[cur] + 1;
                q.push(next);
            }
        }
    }
}