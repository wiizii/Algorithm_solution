#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
string board[101];
int check[101][101][4];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int>> C;

int main() {
    int w, h;
    int ans = 0;
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++) {
            board[i][j] = s[j];
            if (board[i][j] == 'C') C.push_back({i, j});
            for (int k = 0; k < 4; k++) check[i][j][k] = INF;
        }
    }
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < 4; i++) {
        q.push({{C[0].first, C[0].second}, i});
        check[C[0].first][C[0].second][i] = 0;
    }
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= h || nx < 0 || ny >= w || ny < 0) continue;
            if (board[nx][ny] == '*') continue;
            if (i == d) {
                check[nx][ny][i] = check[x][y][d];
            } else
                check[nx][ny][i] = check[x][y][d] + 1;
        }
    }
    cout << ans << "\n";
}