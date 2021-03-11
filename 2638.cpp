#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int, int>
using namespace std;

int n, m;
int cheeze = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int arr[101][101];
bool air[101][101];

void find_air(int a, int b) {
    if (air[a][b]) return;
    queue<pii> q;
    air[a][b] = true;
    q.push({a, b});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!air[nx][ny] && !arr[nx][ny]) {
                air[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    int answer = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j]) cheeze++;
        }
    find_air(0, 0);
    while (cheeze) {
        vector<pii> v;
        answer++;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j]) {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (air[nx][ny]) cnt++;
                    }
                    if (cnt > 1) v.push_back({i, j});
                }
            }
        }
        for (int i = 0; i < v.size(); i++) {
            int x = v[i].first;
            int y = v[i].second;
            arr[x][y] = 0;
            find_air(x, y);
        }
        cheeze -= v.size();
        v.clear();
    }
    cout << answer << "\n";
}