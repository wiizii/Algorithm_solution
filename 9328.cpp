#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char board[102][102];
bool check[102][102];
int n, m;
bool key[26];
map<char, vector<pair<int, int>>> door;

void init() {
    memset(check, 0, sizeof(check));
    memset(key, 0, sizeof(key));
    door.clear();
}

void input() {
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++) board[i][0] = board[i][m + 1] = '.';
    for (int i = 0; i <= m + 1; i++) board[0][i] = board[n + 1][i] = '.';
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> board[i][j];
    string k;
    cin >> k;
    if (k == "0") return;
    for (int i = 0; i < k.size(); i++) key[k[i] - 'a'] = true;
}

int bfs() {
    int ret = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    check[0][0] = true;
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
            if (check[nx][ny]) continue;
            if ('a' <= board[nx][ny] && board[nx][ny] <= 'z' &&
                !key[board[nx][ny] - 'a']) {
                key[board[nx][ny] - 'a'] = true;
                vector<pair<int, int>> &tmp = door[board[nx][ny] - 'a' + 'A'];
                for (int j = 0; j < tmp.size(); j++) {
                    int _x = tmp[j].first;
                    int _y = tmp[j].second;
                    check[_x][_y] = true;
                    q.push({_x, _y});
                }
                tmp.clear();
                check[nx][ny] = true;
                q.push({nx, ny});
            } else if ('A' <= board[nx][ny] && board[nx][ny] <= 'Z' &&
                       !key[board[nx][ny] - 'A']) {
                door[board[nx][ny]].push_back({nx, ny});
            } else {
                if (board[nx][ny] == '$') ret++;
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        init();
        input();
        cout << bfs() << "\n";
    }
}