#include <algorithm>
#include <iostream>
using namespace std;

int n;
int board[10][10];
int dx[] = {-1, -1};
int dy[] = {1, -1};

bool isPossible(int x, int y) {
    for (int i = 0; i < 2; i++) {
        int nx = x;
        int ny = y;
        while (nx + dx[i] >= 0 && ny + dy[i] >= 0 && ny + dy[i] < n) {
            nx += dx[i], ny += dy[i];
            if (board[nx][ny] == 2) return false;
        }
    }
    return true;
}

void solve(int cnt, int v, int *ans) {
    if (cnt == n * n || cnt == n * n + 1) {
        *ans = max(*ans, v);
        return;
    }
    int x = cnt / n;
    int y = cnt % n;
    if (cnt % 2 == 0 && n % 2 == 0 && x % 2 == 1) {
        y++;
    }
    if (cnt % 2 == 1 && n % 2 == 0 && x % 2 == 1) {
        y--;
    }
    if (board[x][y] == 0)
        solve(cnt + 2, v, ans);
    else {
        if (isPossible(x, y)) {
            board[x][y] = 2;
            solve(cnt + 2, v + 1, ans);
            board[x][y] = 1;
        }
        solve(cnt + 2, v, ans);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> board[i][j];
    int w = 0, b = 0;
    solve(0, 0, &w);
    solve(1, 0, &b);
    cout << w + b << "\n";
}
