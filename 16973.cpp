#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int h, w, sr, sc, fr, fc;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int arr[1002][1002];
int check[1002][1002];

void solve(int sx, int sy) {
    queue<pair<int, int>> q;
    check[sx][sy] = 0;
    q.push({sx, sy});
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr <= 0 || nc <= 0 || nr + h - 1 > n || nc + w - 1 > m)
                continue;
            if (check[nr][nc] != -1) continue;
            bool flag = true;
            for (int j = nr; j < nr + h; j++) {
                if (arr[j][nc] || arr[j][nc + w - 1]) {
                    flag = false;
                    break;
                }
            }
            for (int j = nc; j < nc + w; j++) {
                if (arr[nr][j] || arr[nr + h - 1][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                check[nr][nc] = check[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(check, -1, sizeof(check));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> arr[i][j];
    cin >> h >> w >> sr >> sc >> fr >> fc;
    solve(sr, sc);
    if (check[fr][fc] == -1)
        cout << -1 << "\n";
    else
        cout << check[fr][fc] << "\n";
}