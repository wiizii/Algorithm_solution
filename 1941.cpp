#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int n = 5;

char arr[n][n];
bool check[n][n];
bool isVisit[n][n];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int answer = 0;

bool isValidate(int _x, int _y) {
    int a = 0, b = 0;
    memset(isVisit, 0, sizeof(isVisit));
    queue<pii> q;
    q.push({_x, _y});
    isVisit[_x][_y] = true;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (arr[x][y] == 'S') a++;
        if (arr[x][y] == 'Y') b++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (check[nx][ny] && !isVisit[nx][ny]) {
                q.push({nx, ny});
                isVisit[nx][ny] = true;
            }
        }
    }
    if (a + b == 7 && a >= 4)
        return true;
    else
        return false;
}

void solve(int idx, int cnt) {
    if (cnt == 7) {
        int x, y;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (check[i][j]) x = i, y = j;
        if (isValidate(x, y)) answer++;
        return;
    }
    for (int i = idx; i < n * n; i++) {
        int x = i / n;
        int y = i % n;
        check[x][y] = true;
        solve(i + 1, cnt + 1);
        check[x][y] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> arr[i][j];

    solve(0, 0);

    cout << answer << "\n";
}