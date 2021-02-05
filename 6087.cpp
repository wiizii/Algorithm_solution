#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
string board[101];
int check[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
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
        }
    }
    memset(check, -1, sizeof(check));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < 4; i++) {
        q.push({{C[0].first, C[0].second}, i});
        check[C[0].first][C[0].second] = 0;
    }
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        if (x == C[1].first && y == C[1].second) {
            ans = check[x][y];
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= h || nx < 0 || ny >= w || ny < 0 || board[nx][ny] == '*')
                continue;
            if (check[nx][ny] == -1) {
                if (d == i)
                    check[nx][ny] = check[x][y];
                else
                    check[nx][ny] = check[x][y] + 1;
                q.push({{nx, ny}, i});
            } else {
                if (d == i && check[nx][ny] > check[x][y])
                    check[nx][ny] = check[x][y];
                else if(d != i && check[nx][ny] > check[x][y]+1)
                    check[nx][ny] = check[x][y] + 1;
                q.push({{nx, ny}, i});
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << check[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << ans << "\n";
}