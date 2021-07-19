#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int n = 12;
const int m = 6;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

char arr[n][m];

bool bfs(int i, int j) {
    queue<pii> q;
    set<pii> s;
    bool flag = false;
    q.push({i, j});
    s.insert({i, j});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == '.')
                continue;
            if (!s.count({nx, ny}) && arr[nx][ny] == arr[x][y]) {
                q.push({nx, ny});
                s.insert({nx, ny});
            }
        }
    }
    if (s.size() >= 4) {
        for (auto iter = s.begin(); iter != s.end(); iter++) {
            auto [x, y] = *iter;
            arr[x][y] = '.';
        }
        flag = true;
    }
    return flag;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    int cnt = 0;
    while (1) {
        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (bfs(i, j)) flag = true;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] != '.') {
                    int k = i;
                    while (k + 1 < n && arr[k + 1][j] == '.') {
                        arr[k + 1][j] = arr[k][j];
                        arr[k][j] = '.';
                        k++;
                    }
                }
            }
        }

        if (!flag) break;
        cnt++;
    }
    cout << cnt << "\n";
}