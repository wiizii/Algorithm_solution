#include <cstring>
#include <iostream>
using namespace std;

int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char arr[51][51];
bool check[51][51];
bool flag = false;

void dfs(int sx, int sy, int x, int y, int d) {
    check[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m ||
            arr[sx][sy] != arr[nx][ny])
            continue;
        if (nx == sx && ny == sy && d >= 3) {
            flag = true;
            return;
        }
        if (!check[nx][ny]) {
            dfs(sx, sy, nx, ny, d + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            memset(check, 0, sizeof(check));
            dfs(i, j, i, j, 0);
        }

    if (flag)
        cout << "Yes\n";
    else
        cout << "No\n";
}