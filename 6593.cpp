#include <bits/stdc++.h>
using namespace std;
using tiii = tuple<int, int, int>;

char arr[31][31][31];
int check[31][31][31];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

tiii START, END;
int n, m, o;

int bfs() {
    memset(check, -1, sizeof(check));
    queue<tiii> q;
    q.push(START);
    auto [a, b, c] = START;
    check[a][b][c] = 0;
    while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= o)
                continue;
            if (check[nx][ny][nz] == -1 && arr[nx][ny][nz] != '#') {
                check[nx][ny][nz] = check[x][y][z] + 1;
                if (arr[nx][ny][nz] == 'E') {
                    return check[nx][ny][nz];
                }
                q.push({nx, ny, nz});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (1) {
        cin >> n >> m >> o;
        if (n == 0 && m == 0 && o == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < o; k++) {
                    cin >> arr[i][j][k];
                    if (arr[i][j][k] == 'S') START = {i, j, k};
                    if (arr[i][j][k] == 'E') END = {i, j, k};
                }
            }
        }
        int ans = bfs();
        if (ans == -1)
            cout << "Trapped!\n";
        else
            cout << "Escaped in " << ans << " minute(s).\n";
    }
}