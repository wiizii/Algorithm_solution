#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;

char board[102][102];
int check[102][102][3];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

void bfs(int sx, int sy, int k) {
    deque<pair<int, int>> dq;
    dq.push_back({sx, sy});
    check[sx][sy][k] = 0;
    while (!dq.empty()) {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n + 2 || ny >= m + 2 ||
                board[nx][ny] == '*')
                continue;
            if (check[nx][ny][k] == -1) {
                if (board[nx][ny] == '#') {
                    check[nx][ny][k] = check[x][y][k] + 1;
                    dq.push_back({nx, ny});
                } else if (board[nx][ny] == '.') {
                    check[nx][ny][k] = check[x][y][k];
                    dq.push_front({nx, ny});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        memset(check, -1, sizeof(check));
        int ans = INF;
        vector<pair<int, int>> p;
        cin >> n >> m;
        for (int i = 0; i <= n + 1; i++) board[i][0] = board[i][m + 1] = '.';
        for (int j = 0; j <= m + 1; j++) board[0][j] = board[n + 1][j] = '.';
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> board[i][j];
                if (board[i][j] == '$') {
                    board[i][j] = '.';
                    p.push_back({i, j});
                }
            }
        }

        bfs(0, 0, 0);
        bfs(p[0].first, p[0].second, 1);
        bfs(p[1].first, p[1].second, 2);
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= m + 1; j++) {
                if (board[i][j] == '*' || check[i][j][0] == -1) continue;
                if (board[i][j] == '#') {
                    int chk = check[i][j][0] + check[i][j][1] + check[i][j][2];
                    ans = min(ans, chk - 2);
                } else {
                    int chk = check[i][j][0] + check[i][j][1] + check[i][j][2];
                    ans = min(ans, chk);
                }
            }
        }
        if (ans == INF)
            cout << 0 << "\n";
        else
            cout << ans << "\n";
    }
}