#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int arr[101][101];
bool check[101][101];
int n;

int bfs(int minValue, int maxValue) {
    if (arr[0][0] < minValue || arr[0][0] > maxValue) return false;
    memset(check, 0, sizeof(check));
    queue<pii> q;
    q.push({0, 0});
    check[0][0] = true;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == n - 1 && y == n - 1) return true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (!check[nx][ny] && minValue <= arr[nx][ny] &&
                arr[nx][ny] <= maxValue) {
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return false;
}

bool isPossible(int mid) {
    for (int i = 0; i + mid <= 200; i++) {
        if (bfs(i, i + mid)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> arr[i][j];

    int l = 0, r = 200;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (isPossible(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}