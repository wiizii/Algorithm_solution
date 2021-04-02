#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
bool board[18][18];
bool check[18][18];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;

void init() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) check[i][j] = board[i][j];
}

void click(int x, int y) {
    check[x][y] = !check[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        check[nx][ny] = !check[nx][ny];
    }
}

int main() {
    int ans = INF;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> board[i][j];
    int set = (1 << n) - 1;
    for (int subset = set;; subset = ((subset - 1) & set)) {
        int tmp = 0;
        init();
        for (int i = 0; i < n; i++) {
            int b = 1 << i;
            if ((subset | b) == subset) {
                click(0, i);
                tmp++;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (check[i - 1][j]) {
                    click(i, j);
                    tmp++;
                }
            }
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (check[i][j]) flag = false;
            }
        }
        if (flag) ans = min(ans, tmp);
        if (!subset) break;
    }
    if (ans == INF)
        cout << -1 << "\n";
    else
        cout << ans;
}