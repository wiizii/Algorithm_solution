#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

char board[8][8];
bool check[8][8][9];
int dx[] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, 0, -1, 1, 0, -1};

int main() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) cin >> board[i][j];
    queue<tuple<int, int, int>> q;
    check[7][0][0] = true;
    q.push({7, 0, 0});
    while (!q.empty()) {
        int x, y, t;
        tie(x, y, t) = q.front();
        q.pop();
        if (x == 0 && y == 7) {
            cout << 1 << "\n";
            return 0;
        }
        for (int i = 0; i < 9; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nt = min(t + 1, 8);
            if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
            if (nx - t >= 0 && board[nx - t][ny] == '#') continue;
            if (nx - t - 1 >= 0 && board[nx - t - 1][ny] == '#') continue;
            if (!check[nx][ny][nt]) {
                check[nx][ny][nt] = true;
                q.push({nx, ny, nt});
            }
        }
    }
    cout << 0 << "\n";
}