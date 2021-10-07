#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int MAX = 51;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char arr[MAX][MAX];
int check[MAX][MAX][1 << 6];
int n, m;

int bfs(int _x, int _y) {
    memset(check, -1, sizeof(check));
    queue<tiii> q;
    q.push({_x, _y, 0});
    check[_x][_y][0] = 0;
    while (!q.empty()) {
        auto [x, y, mask] = q.front();
        q.pop();
        if (arr[x][y] == '1') {
            return check[x][y][mask];
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == '#')
                continue;
            if (check[nx][ny][mask] == -1) {
                if (islower(arr[nx][ny])) {
                    int newMask = mask | (1 << (arr[nx][ny] - 'a'));
                    check[nx][ny][newMask] = check[x][y][mask] + 1;
                    q.push({nx, ny, newMask});
                } else if (isupper(arr[nx][ny])) {
                    int keyBit = 1 << (arr[nx][ny] - 'A');
                    if (mask & keyBit) {
                        check[nx][ny][mask] = check[x][y][mask] + 1;
                        q.push({nx, ny, mask});
                    }
                } else {
                    check[nx][ny][mask] = check[x][y][mask] + 1;
                    q.push({nx, ny, mask});
                }
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    pii start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '0') start = {i, j};
        }
    }

    int answer = bfs(start.first, start.second);
    cout << answer << "\n";
}