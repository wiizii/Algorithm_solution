#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int arr[101][101];
int check[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

int bfs() {
    queue<pii> q;
    int ret = 0;
    memset(check, 0, sizeof(check));
    q.push({0, 0});
    check[0][0] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (arr[nx][ny] == 0 && !check[nx][ny]) {
                check[nx][ny] = 1;
                q.push({nx, ny});
            }
            if (arr[nx][ny] == 1 && !check[nx][ny]) {
                check[nx][ny] = -1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check[i][j] == -1) {
                ret++;
                arr[i][j] = 0;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans1 = 0;
    int ans2 = 0;
    int remain = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j]) remain++;
        }
    }
    while (remain) {
        int next = bfs();
        if (remain - next == 0) ans2 = remain;
        ans1++;
        remain -= next;
    }
    cout << ans1 << "\n" << ans2;
}