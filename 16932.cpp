#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int arr[1001][1001];
int check[1001][1001];
int cnt[1000001];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int i, int j, int k) {
    queue<pii> q;
    check[i][j] = k;
    cnt[k]++;
    q.push({i, j});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int t = 0; t < 4; t++) {
            int nx = x + dx[t];
            int ny = y + dy[t];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || !arr[nx][ny])
                continue;
            if (!check[nx][ny]) {
                check[nx][ny] = k;
                cnt[k]++;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] && !check[i][j]) bfs(i, j, ++k);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!arr[i][j]) {
                set<int> s;
                for (int t = 0; t < 4; t++) {
                    int nx = i + dx[t];
                    int ny = j + dy[t];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    s.insert(check[nx][ny]);
                }
                int tmp = 0;
                for (auto iter = s.begin(); iter != s.end(); iter++)
                    tmp += cnt[*iter];
                tmp++;
                ans = max(ans, tmp);
            } else {
                ans = max(ans, arr[i][j]);
            }
        }
    }
    cout << ans << "\n";
}