#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
char board[10][10];
char check[10][10];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void init() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) check[i][j] = board[i][j];
}

void toggle(char *c) {
    if (*c == '#')
        *c = 'O';
    else
        *c = '#';
}

void click(int x, int y) {
    toggle(&check[x][y]);
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;
        toggle(&check[nx][ny]);
    }
}

int main() {
    int ans = INF;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) cin >> board[i][j];
    int set = (1 << 10) - 1;
    for (int subset = set;; subset = ((subset - 1) & set)) {
        int tmp = 0;
        init();
        for (int i = 0; i < 10; i++) {
            int b = 1 << i;
            if ((subset | b) == subset) {
                click(0, i);
                tmp++;
            }
        }
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (check[i - 1][j] == 'O') {
                    click(i, j);
                    tmp++;
                }
            }
        }
        bool flag = true;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (check[i][j] == 'O') flag = false;
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