#include <iostream>
#include <set>
#include <vector>
using namespace std;

char map[20][20];
int check[20][20];
set<char> s;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int r, c, ans = 1;

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        if (s.size() > check[nx][ny] && !s.count(map[nx][ny])) {
            check[nx][ny] = s.size();
            s.insert(map[nx][ny]);
            if (ans < s.size()) ans = s.size();
            dfs(nx, ny);
            check[nx][ny] = s.size() - 1;
            s.erase(map[nx][ny]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> map[i][j];
    check[0][0] = 1;
    s.insert(map[0][0]);
    dfs(0, 0);
    cout << ans << "\n";
    return 0;
}
// ff