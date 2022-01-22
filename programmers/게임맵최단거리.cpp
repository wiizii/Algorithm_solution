#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int check[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int solution(vector<vector<int>> maps) {
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    queue<pair<int, int>> q;
    q.push({0, 0});
    check[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == n - 1 && y == m - 1) return check[x][y];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || !maps[nx][ny])
                continue;
            if (!check[nx][ny]) {
                check[nx][ny] = check[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}