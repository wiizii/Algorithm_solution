#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

int r, c;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
char map[50][50];
int check[50][50];
queue<pair<int, int>> h, w;

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S') {
                h.push({i, j});
                check[i][j] = 1;
            } else if (map[i][j] == '*')
                w.push({i, j});
        }
    }
    while (!h.empty()) {
        queue<pair<int, int>> nw, nh;
        while (1) {
            if (w.empty()) {
                break;
            }
            int cur_r = w.front().first;
            int cur_c = w.front().second;
            w.pop();
            for (int i = 0; i < 4; i++) {
                int nr = cur_r + dr[i];
                int nc = cur_c + dc[i];
                if (nr < 0 || nc < 0 || nr >= r || nc >= c) {
                    continue;
                }
                if (map[nr][nc] == '.' || map[nr][nc] == 'S') {
                    map[nr][nc] = '*';
                    nw.push({nr, nc});
                }
            }
            if (w.empty()) {
                w = nw;
                break;
            }
        }
        while (1) {
            int cur_r = h.front().first;
            int cur_c = h.front().second;
            h.pop();
            for (int i = 0; i < 4; i++) {
                int nr = cur_r + dr[i];
                int nc = cur_c + dc[i];
                if (nr < 0 || nc < 0 || nr >= r || nc >= c) continue;
                if (!check[nr][nc] && map[nr][nc] != '*' &&
                    map[nr][nc] != 'X') {
                    if (map[nr][nc] == 'D') {
                        cout << check[cur_r][cur_c] << '\n';
                        exit(0);
                    }
                    check[nr][nc] = check[cur_r][cur_c] + 1;
                    nh.push({nr, nc});
                }
            }
            if (h.empty()) {
                h = nh;
                break;
            }
        }
    }
    cout << "KAKTUS\n";
    return 0;
}