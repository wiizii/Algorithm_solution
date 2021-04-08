#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
char arr[101][101];
bool check[101][101];

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    check[sx][sy] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == '.')
                continue;
            if (!check[nx][ny]) {
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

void left_shoot(int k) {
    for (int i = 0; i < m; i++) {
        if (arr[k][i] == 'x') {
            arr[k][i] = '.';
            return;
        }
    }
}
void right_shoot(int k) {
    for (int i = m - 1; i >= 0; i--) {
        if (arr[k][i] == 'x') {
            arr[k][i] = '.';
            return;
        }
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second < b.second)
        return true;
    else if (a.second == b.second)
        return a.first > b.first;
    else
        return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    int t;
    cin >> t;
    bool left = true;
    while (t--) {
        int k;
        cin >> k;
        if (left)
            left_shoot(n - k);
        else
            right_shoot(n - k);
        left = !left;
        memset(check, 0, sizeof(check));
        for (int i = 0; i < m; i++)
            if (arr[n - 1][i] == 'x' && !check[n - 1][i]) bfs(n - 1, i);
        vector<pair<int, int>> cluster;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (arr[i][j] == 'x' && !check[i][j]) cluster.push_back({i, j});
        sort(cluster.begin(), cluster.end(), cmp);
        int dep = 0x3f3f3f3f;
        for (int i = 0; i < cluster.size(); i++) {
            int x = cluster[i].first;
            int y = cluster[i].second;
            int tmp = 0;
            if (i != 0 && cluster[i - 1].second == y) continue;
            while (x + 1 < n && arr[x + 1][y] != 'x') x++, tmp++;
            dep = min(dep, tmp);
        }
        for (int i = 0; i < cluster.size(); i++) {
            int x = cluster[i].first;
            int y = cluster[i].second;
            arr[x][y] = '.';
            arr[x + dep][y] = 'x';
        }
    }
    print();
}