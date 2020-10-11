#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

char map[1000][1000];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        memset(map, 0, sizeof(map));
        queue<pair<int, int>> s, fire;
        bool flag = false;
        int w, h, ans = 0;
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
                if (map[i][j] == '@') {
                    s.push({i, j});
                }
                if (map[i][j] == '*') {
                    fire.push({i, j});
                }
            }
        }
        while (!s.empty()) {
            queue<pair<int, int>> sNext, fireNext;
            ans++;
            while (!fire.empty()) {
                int x = fire.front().first;
                int y = fire.front().second;
                fire.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                    if (map[nx][ny] == '.' || map[nx][ny] == '@') {
                        map[nx][ny] = '*';
                        fireNext.push({nx, ny});
                    }
                }
            }
            while (!s.empty()) {
                int x = s.front().first;
                int y = s.front().second;
                s.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
                        flag = true;
                        continue;
                    }
                    if (map[nx][ny] == '.') {
                        map[nx][ny] = '@';
                        sNext.push({nx, ny});
                    }
                }
            }
            if (flag) {
                cout << ans << "\n";
                break;
            }
            s = sNext;
            fire = fireNext;
        }
        if (!flag) {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}