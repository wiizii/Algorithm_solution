#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char arr[251][251];
bool check[251][251];
int r, c;

pii bfs(int _x, int _y) {
    pii ret;
    ret.first = ret.second = 0;
    queue<pii> q;
    q.push({_x, _y});
    check[_x][_y] = true;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= r || ny >= c || arr[nx][ny] == '#')
                continue;
            if (!check[nx][ny]) {
                check[nx][ny] = true;
                if (arr[nx][ny] == 'o') ret.first++;
                if (arr[nx][ny] == 'v') ret.second++;
                q.push({nx, ny});
            }
        }
    }
    if (ret.first > ret.second)
        ret.second = 0;
    else
        ret.first = 0;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pii ans;
    ans.first = ans.second = 0;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> arr[i][j];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] != '#' || check[i][j] == true) continue;
            pii tmp = bfs(i, j);
            ans.first += tmp.first;
            ans.second += tmp.second;
        }
    }
    cout << ans.first << " " << ans.second << "\n";
}