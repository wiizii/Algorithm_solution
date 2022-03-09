#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int MAX = 51;

int n;
int ans = 0;
char arr[MAX][MAX];
bool check[MAX][MAX];
int dx[] = {-1, -1, 0, 1, 1, 0};
int dy[] = {0, 1, 1, 0, -1, -1};

void bfs(int _i, int _j) {
    queue<pii> q;
    q.push({_i, _j});
    check[_i][_j] = true;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        int cnt = 0;
        int flag = 0;
        for (int i = 0; i < 7; i++) {
            int nx = x + dx[i % 6];
            int ny = y + dy[i % 6];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] == '-') {
                flag = 0;
                continue;
            }
            if (i != 6) {
                cnt++;
            }
            flag++;
            if (cnt > 0) {
                ans = max(ans, 2);
            }
            if (flag >= 2) {
                ans = max(ans, 3);
            }

            if (!check[nx][ny]) {
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!check[i][j] && arr[i][j] == 'X') {
                ans = max(ans, 1);
                bfs(i, j);
            }
        }
    }
    cout << ans << "\n";
}