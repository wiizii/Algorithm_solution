#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int MAX = 1001;

char arr[MAX][MAX];
bool check[MAX][MAX];
int sx, sy;
int r, c;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<pii> fire;

int bfs() {
    queue<tiii> q;
    q.push({sx, sy, 0});
    check[sx][sy] = true;
    int a = -1;
    while (!q.empty()) {
        auto [x, y, cnt] = q.front();
        q.pop();
        if (x == 0 || y == 0 || x == r - 1 || y == c - 1) return cnt;
        if (a != cnt) {
            int size = fire.size();
            for (int i = 0; i < size; i++) {
                for (int k = 0; k < 4; k++) {
                    int nx = fire[i].first + dx[k];
                    int ny = fire[i].second + dy[k];
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c ||
                        arr[nx][ny] == '#' || arr[nx][ny] == 'F')
                        continue;
                    arr[nx][ny] = 'F';
                    fire.push_back({nx, ny});
                }
            }
            a = cnt;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (arr[nx][ny] == '.' && !check[nx][ny]) {
                check[nx][ny] = true;
                q.push({nx, ny, cnt + 1});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'J') sx = i, sy = j;
            if (arr[i][j] == 'F') fire.push_back({i, j});
        }
    }

    int ans = bfs();

    if (ans == -1)
        cout << "IMPOSSIBLE\n";
    else
        cout << ans + 1 << '\n';
    return 0;
}