#include <algorithm>
#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int ans = INF;
char arr[20][20];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
vector<pii> v;

void solve(int r1, int c1, int r2, int c2, int d) {
    if (d == 11) return;
    if ((r1 < 0 || c1 < 0 || r1 >= n || c1 >= m) &&
        (r2 >= 0 && c2 >= 0 && r2 < n && c2 < m)) {
        ans = min(ans, d);
        return;
    }
    if ((r1 >= 0 && c1 >= 0 && r1 < n && c1 < m) &&
        (r2 < 0 || c2 < 0 || r2 >= n || c2 >= m)) {
        ans = min(ans, d);
        return;
    }
    if ((r1 < 0 || c1 < 0 || r1 >= n || c1 >= m) &&
        (r2 < 0 || c2 < 0 || r2 >= n || c2 >= m)) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nr1 = r1 + dr[i];
        int nc1 = c1 + dc[i];
        int nr2 = r2 + dr[i];
        int nc2 = c2 + dc[i];
        if (arr[nr1][nc1] == '#') {
            nr1 -= dr[i];
            nc1 -= dc[i];
        }
        if (arr[nr2][nc2] == '#') {
            nr2 -= dr[i];
            nc2 -= dc[i];
        }
        solve(nr1, nc1, nr2, nc2, d + 1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'o') v.push_back({i, j});
        }
    }
    int r1 = v[0].first;
    int c1 = v[0].second;
    int r2 = v[1].first;
    int c2 = v[1].second;
    solve(r1, c1, r2, c2, 0);
    if (ans == INF)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}