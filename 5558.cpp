#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
int n, m, c;
char arr[1001][1001];
int check[1001][1001];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(int &sx, int &sy, int c) {
    memset(check, -1, sizeof(check));
    queue<pii> q;
    q.push({sx, sy});
    check[sx][sy] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (arr[x][y] == '0' + c) {
            sx = x, sy = y;
            return check[x][y];
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == 'X')
                continue;
            if (check[nx][ny] == -1) {
                check[nx][ny] = check[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int sx, sy;
    int answer = 0;
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') sx = i, sy = j;
        }
    }
    for (int i = 1; i <= c; i++) answer += bfs(sx, sy, i);
    cout << answer << "\n";
}