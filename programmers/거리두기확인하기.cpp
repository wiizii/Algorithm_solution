#include <bits/stdc++.h>

using namespace std;
using tiii = tuple<int, int, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool bfs(int _x, int _y, vector<string> &p) {
    bool check[5][5];
    memset(check, 0, sizeof(check));
    queue<tiii> q;
    q.push({_x, _y, 0});
    check[_x][_y] = true;
    while (!q.empty()) {
        auto [x, y, d] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || check[nx][ny] ||
                p[nx][ny] == 'X')
                continue;
            if (p[nx][ny] == 'P') return false;
            if (d < 1) {
                check[nx][ny] = true;
                q.push({nx, ny, d + 1});
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int n = 5;
    for (int t = 0; t < n; t++) {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (places[t][i][j] == 'P' && !bfs(i, j, places[t])) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag)
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    return answer;
}