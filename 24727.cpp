#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int MAX = 101;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;
int arr[MAX][MAX];

bool isValid(int x, int y, int c) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (arr[nx][ny] != 0 && arr[nx][ny] != c) {
            return false;
        }
    }
    return true;
}

bool solve(int _x, int _y, int c, int cnt) {
    queue<pii> q;
    q.push({_x, _y});
    arr[_x][_y] = c;
    cnt--;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (!cnt) {
                return true;
            }
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny] != 0) {
                continue;
            }
            if (isValid(nx, ny, c)) {
                cnt--;
                arr[nx][ny] = c;
                q.push({nx, ny});
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> n >> a >> b;
    if (n == 1) {
        cout << "-1\n";
        return 0;
    }
    bool answer = solve(0, 0, 1, a) && solve(n - 1, n - 1, 2, b);
    if (answer) {
        cout << "1\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j];
            }
            cout << "\n";
        }
    } else {
        cout << "-1\n";
    }
}