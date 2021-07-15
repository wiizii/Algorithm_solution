#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<string> board;
int check[102][102];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<pair<int, int>> tile[26];

bool find_pair(int sx, int sy, int ex, int ey, int num) {
    check[sx][sy] = num;
    for (int i = 0; i < 4; i++) {
        int nx = sx + dx[i];
        int ny = sy + dy[i];
        while (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            if (board[nx][ny] != '.') break;
            check[nx][ny] = num;
            nx += dx[i];
            ny += dy[i];
        }
    }
    for (int i = 0; i < 4; i++) {
        int nx = ex + dx[i];
        int ny = ey + dy[i];
        while (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            if (check[nx][ny] == num) return true;
            if (board[nx][ny] != '.') break;
            nx += dx[i];
            ny += dy[i];
        }
    }
    return false;
}

string solution(int mm, int nn, vector<string> b) {
    n = mm, m = nn;
    board = b;
    string answer = "";
    memset(check, -1, sizeof(check));
    int cnt = 0;
    for (int i = 0; i < 26; i++) tile[i].clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isupper(board[i][j])) {
                tile[board[i][j] - 'A'].push_back({i, j});
                cnt++;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (!tile[i].empty()) {
            auto [sx, sy] = tile[i][0];
            auto [ex, ey] = tile[i][1];
            if (find_pair(sx, sy, ex, ey, i)) {
                cnt -= 2;
                answer.push_back(board[sx][sy]);
                board[sx][sy] = board[ex][ey] = '.';
                tile[i].clear();
                i = -1;
            }
        }
    }
    if (cnt != 0) answer = "IMPOSSIBLE";
    return answer;
}