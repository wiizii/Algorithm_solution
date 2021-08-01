#include <bits/stdc++.h>
using namespace std;
using tiii = tuple<int, int, int>;

int arr[1001][1001];
int check[1001][1001][2];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, hx, hy, ex, ey;

int bfs() {
    queue<tiii> q;
    q.push({hx, hy, 0});
    check[hx][hy][0] = 0;
    while (!q.empty()) {
        auto [x, y, isBroken] = q.front();
        q.pop();
        if (x == ex && y == ey) return check[x][y][isBroken];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (isBroken) {
                if (arr[nx][ny] == 0 && check[nx][ny][1] == -1) {
                    check[nx][ny][1] = check[x][y][1] + 1;
                    q.push({nx, ny, 1});
                }
            } else {
                if (arr[nx][ny] == 1 && check[nx][ny][1] == -1) {
                    check[nx][ny][1] = check[x][y][0] + 1;
                    q.push({nx, ny, 1});
                }
                if (arr[nx][ny] == 0 && check[nx][ny][0] == -1) {
                    check[nx][ny][0] = check[x][y][0] + 1;
                    q.push({nx, ny, 0});
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(check, -1, sizeof(check));
    cin >> n >> m >> hx >> hy >> ex >> ey;
    hx--, hy--, ex--, ey--;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    cout << bfs() << "\n";
}