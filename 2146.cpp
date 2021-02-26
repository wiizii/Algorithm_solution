#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int color = 1;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int board[101][101];
int map[101][101];
vector<pair<pair<int, int>, int>> edge;

void find_island(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    map[i][j] = color;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (!map[nx][ny] && board[nx][ny]) {
                map[nx][ny] = color;
                q.push({nx, ny});
            }
        }
    }
    color++;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> board[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] && !map[i][j]) find_island(i, j);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j]) {
                bool flag = false;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (map[nx][ny] == 0) flag = true;
                }
                if (flag) edge.push_back({{i, j}, map[i][j]});
            }
        }
    }

    int ans = 0x3f3f3f3f;
    for (int i = 0; i < edge.size(); i++) {
        for (int j = i + 1; j < edge.size(); j++) {
            if (edge[i].second == edge[j].second) continue;
            int dist = abs(edge[i].first.first - edge[j].first.first) +
                       abs(edge[i].first.second - edge[j].first.second);
            ans = min(ans, dist);
        }
    }

    cout << ans - 1 << "\n";
}