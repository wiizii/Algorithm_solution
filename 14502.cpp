#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[8][8];
int check[8][8];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
int ans = 0;
vector<pair<int, int> > virus;

void copy() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            check[i][j] = arr[i][j];
        }
    }
}

void bfs() {
    queue<pair<int, int> > q;
    for (int i = 0; i < virus.size(); i++)
        q.push({virus[i].first, virus[i].second});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (!check[nx][ny]) {
                check[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }

    int safe = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check[i][j] == 0) safe++;
        }
    }
    ans = max(ans, safe);
}

void bt(int num) {
    if (num == 3) {
        copy();
        bfs();
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!arr[i][j]) {
                arr[i][j] = 1;
                bt(num + 1);
                arr[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) virus.push_back({i, j});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = 1;
                bt(1);
                arr[i][j] = 0;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
