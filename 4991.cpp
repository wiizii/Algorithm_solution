#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char board[21][21];
bool check[21][21];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

int get_dist(int sx, int sy, int ex, int ey) {
    queue<pair<pair<int, int>, int>> q;
    memset(check, 0, sizeof(check));
    q.push({{sx, sy}, 0});
    check[sx][sy] = true;
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second;
        q.pop();
        if (x == ex && y == ey) return t;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nt = t + 1;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] == 'x')
                continue;
            if (!check[nx][ny]) {
                check[nx][ny] = true;
                q.push({{nx, ny}, nt});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (1) {
        int sx = 0, sy = 0;
        int first_dist[11] = {
            0,
        };
        int dist[11][11] = {
            0,
        };
        vector<pair<int, int>> dust;
        int ans = 0x3f3f3f3f;
        cin >> m >> n;
        if (!m && !n) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
                if (board[i][j] == 'o') sx = i, sy = j;
                if (board[i][j] == '*') dust.push_back({i, j});
            }
        }
        bool flag = true;

        for (int i = 0; i < dust.size(); i++)
            first_dist[i] = get_dist(sx, sy, dust[i].first, dust[i].second);
        for (int i = 0; i < dust.size(); i++) {
            for (int j = i + 1; j < dust.size(); j++) {
                dist[i][j] = get_dist(dust[i].first, dust[i].second,
                                      dust[j].first, dust[j].second);
                dist[j][i] = dist[i][j];
                if (dist[i][j] == -1) {
                    flag = false;
                    break;
                }
            }
        }
        if (!flag) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> per;
        for (int i = 0; i < dust.size(); i++) per.push_back(i);
        do {
            int tmp = first_dist[per[0]];
            for (int i = 1; i < per.size(); i++)
                tmp += dist[per[i - 1]][per[i]];
            ans = min(ans, tmp);
        } while (next_permutation(per.begin(), per.end()));
        cout << ans << "\n";
    }
}