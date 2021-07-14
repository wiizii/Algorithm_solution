#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

char arr[51][51];
int check[51][51];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

int bfs(int i, int j) {
    int ret = 0;
    memset(check, -1, sizeof(check));
    queue<pii> q;
    q.push({i, j});
    check[i][j] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == 'W')
                continue;
            if (check[nx][ny] == -1 || check[x][y] + 1 < check[nx][ny]) {
                check[nx][ny] = check[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) ret = max(ret, check[i][j]);
    return ret;
}

int main() {
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'W') continue;
            ans = max(ans, bfs(i, j));
        }
    }
    cout << ans << "\n";
}