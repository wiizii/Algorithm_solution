#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int MAX = 1501;

char m[MAX][MAX];
bool check[MAX][MAX];
bool checkX[MAX][MAX];
int r, c;
vector<pii> swan;
queue<pii> q, tmpQ, q1, q2;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool canMeet() {
    pii e = swan[1];

    while (!q2.empty()) {
        q1.push(q2.front());
        q2.pop();
    }

    while (!q1.empty()) {
        auto [x, y] = q1.front();
        q1.pop();
        if (x == e.first && y == e.second) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                continue;
            }
            if (m[nx][ny] == '.' && !check[nx][ny]) {
                check[nx][ny] = true;
                q1.push({nx, ny});
            }
            if (m[nx][ny] == 'X' && !check[nx][ny]) {
                check[nx][ny] = true;
                q2.push({nx, ny});
            }
        }
    }

    return false;
}

int solve() {
    int ret = 0;
    while (!tmpQ.empty()) {
        ret++;
        while (!tmpQ.empty()) {
            q.push(tmpQ.front());
            tmpQ.pop();
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            m[x][y] = '.';
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                    continue;
                }
                if (m[nx][ny] == 'X' && !checkX[nx][ny]) {
                    checkX[nx][ny] = true;
                    tmpQ.push({nx, ny});
                }
            }
        }
        if (canMeet()) {
            return ret;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> m[i][j];
            if (m[i][j] == 'L') {
                swan.push_back({i, j});
                m[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (m[i][j] == '.') {
                continue;
            }
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                    continue;
                }
                if (m[nx][ny] == '.') {
                    checkX[i][j] = true;
                    tmpQ.push({i, j});
                    break;
                }
            }
        }
    }

    q2.push(swan[0]);
    check[swan[0].first][swan[0].second] = true;

    int answer = solve();

    cout << answer << "\n";

    return 0;
}