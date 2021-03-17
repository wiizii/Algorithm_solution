#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m, k;
int map[1001][1001];
int check[1001][1001][11];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct info {
    int x, y, t, d;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) map[i][j] = s[j] - '0';
    }
    queue<info> q;
    check[0][0][0] = 1;
    q.push({0, 0, 0, 0});
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int t = q.front().t;
        int d = q.front().d;
        q.pop();
        if (x == n - 1 && y == m - 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << check[i][j][1] << " ";
                }
                cout << endl;
            }
            cout << check[x][y][t] << "\n";
            return 0;
        }
        if (t > k) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (map[nx][ny] && !check[nx][ny][t + 1]) {
                if (d) {
                    check[nx][ny][t + 1] = check[x][y][t] + 2;
                    q.push({nx, ny, t + 1, d});
                } else {
                    check[nx][ny][t + 1] = check[x][y][t] + 1;
                    q.push({nx, ny, t + 1, !d});
                }
            }
            if (!map[nx][ny] && !check[nx][ny][t]) {
                check[nx][ny][t] = check[x][y][t] + 1;
                q.push({nx, ny, t, !d});
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}