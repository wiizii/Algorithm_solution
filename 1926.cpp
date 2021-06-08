#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int arr[501][501];
bool check[501][501];
int n, m;

int bfs(int _x, int _y) {
    int ret = 1;
    queue<pii> q;
    q.push({_x, _y});
    check[_x][_y] = true;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || !arr[nx][ny])
                continue;
            if (!check[nx][ny]) {
                check[nx][ny] = true;
                ret++;
                q.push({nx, ny});
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!arr[i][j] || check[i][j]) continue;
            ans1++;
            ans2 = max(ans2, bfs(i, j));
        }
    }
    cout << ans1 << "\n" << ans2 << "\n";
}