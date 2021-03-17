#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;

int n, m;
int arr[1001][1001];
int check[1001][1001];
int ans[1001][1001];
int cnt[1000001];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int sector(int a, int b, int k) {
    int ret = 1;
    queue<pair<int, int>> q;
    check[a][b] = k;
    q.push({a, b});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny]) continue;
            if (!check[nx][ny]) {
                check[nx][ny] = k;
                q.push({nx, ny});
                ret++;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!arr[i][j] && !check[i][j]) {
                cnt[k] = sector(i, j, k);
                k++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j]) {
                ans[i][j]++;
                set<int> s;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny])
                        continue;
                    int nc = check[nx][ny];
                    if (!s.count(nc)) {
                        ans[i][j] += cnt[nc];
                        s.insert(nc);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] % 10;
        }
        cout << "\n";
    }
}