#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int arr[301][301];
int check[301][301];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

void bfs(int _x, int _y) {
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
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> arr[i][j];

    int year = 0;

    for (year = 0; true; year++) {
        int cnt = 0;
        memset(check, 0, sizeof(check));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] && !check[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        if (cnt >= 2) {
            cout << year << "\n";
            break;
        }
        if (cnt == 0) {
            cout << 0 << "\n";
            break;
        }

        memset(check, 0, sizeof(check));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j]) {
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (arr[nx][ny] == 0) check[i][j]++;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (check[i][j]) {
                    if (check[i][j] <= arr[i][j])
                        arr[i][j] -= check[i][j];
                    else
                        arr[i][j] = 0;
                }
            }
        }
    }
}