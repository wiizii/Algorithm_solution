#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, m, sk;
int arr[50][50];
int marble[4];
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
int ddx[] = {0, 1, 0, -1};
int ddy[] = {-1, 0, 1, 0};

void marble_move() {
    queue<int> q;
    int nx = sk, ny = sk;
    int dir = 0;
    for (int i = 1; i < n; i++) {
        int r = (i == n - 1) ? 3 : 2;
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < i; k++) {
                nx += ddx[dir], ny += ddy[dir];
                if (arr[nx][ny]) q.push(arr[nx][ny]);
            }
            dir = (dir + 1) % 4;
        }
    }
    memset(arr, 0, sizeof(arr));
    if (q.empty()) return;
    nx = sk, ny = sk;
    dir = 0;
    for (int i = 1; i < n; i++) {
        int r = (i == n - 1) ? 3 : 2;
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < i; k++) {
                nx += ddx[dir], ny += ddy[dir];
                arr[nx][ny] = q.front();
                q.pop();
                if (q.empty()) return;
            }
            dir = (dir + 1) % 4;
        }
    }
}

bool boom() {
    queue<pii> q;
    bool flag = false;
    int px = sk, py = sk;
    int nx = sk, ny = sk;
    int dir = 0;
    for (int i = 1; i < n; i++) {
        int r = (i == n - 1) ? 3 : 2;
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < i; k++) {
                px = nx, py = ny;
                nx += ddx[dir], ny += ddy[dir];
                if (arr[px][py] == arr[nx][ny])
                    q.push({nx, ny});
                else {
                    if (q.size() >= 4) {
                        while (!q.empty()) {
                            auto [x, y] = q.front();
                            q.pop();
                            marble[arr[x][y]]++;
                            arr[x][y] = 0;
                        }
                        flag = true;
                    } else {
                        while (!q.empty()) q.pop();
                    }
                    q.push({nx, ny});
                }
            }
            dir = (dir + 1) % 4;
        }
    }
    return flag;
}

void make_new() {
    queue<int> q;
    int cnt = 0;
    int px = sk, py = sk;
    int nx = sk, ny = sk;
    int dir = 0;
    for (int i = 1; i < n; i++) {
        int r = (i == n - 1) ? 3 : 2;
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < i; k++) {
                px = nx, py = ny;
                nx += ddx[dir], ny += ddy[dir];
                if (arr[px][py] == arr[nx][ny])
                    cnt++;
                else {
                    if (cnt) {
                        q.push(cnt);
                        q.push(arr[px][py]);
                    }
                    cnt = 1;
                }
            }
            dir = (dir + 1) % 4;
        }
    }
    memset(arr, 0, sizeof(arr));
    if (q.empty()) return;
    nx = sk, ny = sk;
    dir = 0;
    for (int i = 1; i < n; i++) {
        int r = (i == n - 1) ? 3 : 2;
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < i; k++) {
                nx += ddx[dir], ny += ddy[dir];
                arr[nx][ny] = q.front();
                q.pop();
                if (q.empty()) return;
            }
            dir = (dir + 1) % 4;
        }
    }
}

void skill(int d, int s) {
    int nx = sk, ny = sk;
    while (s--) {
        nx += dx[d];
        ny += dy[d];
        arr[nx][ny] = 0;
    }
}

int main() {
    int answer = 0;
    cin >> n >> m;
    sk = n / 2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    while (m--) {
        int d, s;
        cin >> d >> s;
        skill(d, s);
        marble_move();
        while (boom()) marble_move();
        make_new();
    }
    answer = marble[1] + 2 * marble[2] + 3 * marble[3];
    cout << answer << "\n";
}