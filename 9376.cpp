#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;

char board[102][102];
int check[102][102];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

void print() {
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            if (check[i][j] == INF)
                cout << 0;
            else
                cout << board[i][j];
        }
        cout << "\n";
    }
}
int bfs(int sx, int sy, int ex, int ey, bool opt = false) {
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++) check[i][j] = INF;
    queue<pair<int, int>> q;
    q.push({0, 0});
    check[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n + 2 || ny >= m + 2 ||
                board[nx][ny] == '*')
                continue;
            if (board[nx][ny] == '#' && check[nx][ny] > check[x][y] + 1) {
                check[nx][ny] = check[x][y] + 1;
                q.push({nx, ny});
            } else if (check[nx][ny] > check[x][y]) {
                check[nx][ny] = check[x][y];
                q.push({nx, ny});
            }
        }
    }
    return check[ex][ey];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        vector<pair<int, int>> p;
        cin >> n >> m;
        for (int i = 0; i <= n + 1; i++) board[i][0] = board[i][m + 1] = '.';
        for (int j = 0; j <= m + 1; j++) board[0][j] = board[n + 1][j] = '.';
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> board[i][j];
                if (board[i][j] == '$') p.push_back({i, j});
            }
        }
        int a = bfs(0, 0, p[0].first, p[0].second);
        int b = bfs(0, 0, p[1].first, p[1].second);
        int ab = bfs(p[0].first, p[0].second, p[1].first, p[1].second);
        int b0 = bfs(p[1].first, p[1].second, 0, 0, true);

        // print();
        int ans = min(a + b, ab + b);
    }
}