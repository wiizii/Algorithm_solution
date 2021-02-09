#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char board[101][101];
bool check[101][101];
int mirror[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pair<int, int>> C;

int main() {
    int w, h;
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'C') C.push_back({i, j});
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < 4; i++) q.push({C[0].first, C[0].second});
    check[C[0].first][C[0].second] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            while (nx < h && nx >= 0 && ny < w && ny >= 0) {
                if (board[nx][ny] == '*') break;
                if (!check[nx][ny]) {
                    check[nx][ny] = true;
                    mirror[nx][ny] = mirror[x][y] + 1;
                    q.push({nx, ny});
                }
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
    cout << mirror[C[1].first][C[1].second] - 1 << "\n";
}