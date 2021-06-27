#include <bits/stdc++.h>
using namespace std;
using tiii = tuple<int, int, int>;

int n, m;
char arr[101][101];
char aaa[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isRange(int x, int y, int s) {
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= s; j++) {
            int nx = x + dx[i] * j;
            int ny = y + dy[i] * j;
            if (nx <= 0 || ny <= 0 || nx > n || ny > m) return false;
            if (arr[nx][ny] == '.') return false;
        }
    }
    return true;
}

void draw(int x, int y, int s) {
    aaa[x][y] = '*';
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= s; j++) {
            int nx = x + dx[i] * j;
            int ny = y + dy[i] * j;
            aaa[nx][ny] = '*';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<tiii> ans;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            aaa[i][j] = '.';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 3; k >= 1; k--) {
                if (arr[i][j] == '*' && isRange(i, j, k)) {
                    draw(i, j, k);
                    ans.push_back({i, j, k});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] != aaa[i][j]) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        auto [q, w, e] = ans[i];
        cout << q << " " << w << " " << e << "\n";
    }
}