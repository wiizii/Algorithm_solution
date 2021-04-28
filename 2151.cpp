#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;
char board[51][51];
bool check[51][51];
queue<pair<pii, int>> q;
vector<pii> door;

int main() {
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == '#') door.push_back({i, j});
        }
    }

    q.push({door[0], 0});
    check[door[0].first][door[0].second] = true;
    while (!q.empty()) {
        auto [x, y] = q.front().first;
        int m = q.front().second;
        q.pop();
        if (x == door[1].first && y == door[1].second) {
            ans = m;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] == '*')
                continue;
            if (board[nx][ny] == '!') {
            }
        }
    }
    cout << ans << "\n";
}