#include <iostream>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

int dr[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[] = {-2, -1, 1, 2, -2, -1, 1, 2};

void solve(int l, int rs, int cs, int re, int ce, int &ans,
           bool map[300][300]) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{rs, cs}, 0});
    map[rs][cs] = true;
    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        if (r == re && c == ce) {
            ans = d;
            return;
        }
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int nd = d + 1;
            if (nr < 0 || nc < 0 || nr >= l || nc >= l) continue;
            if (!map[nr][nc]) {
              map[nr][nc] = true;
              q.push({{nr,nc},nd}); 
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int l;
        cin >> l;
        bool map[300][300] = {
            0,
        };
        int ans = INF;
        int rs, cs, re, ce;
        cin >> rs >> cs >> re >> ce;
        solve(l, rs, cs, re, ce, ans, map);
        cout << ans << "\n";
    }
    return 0;
}