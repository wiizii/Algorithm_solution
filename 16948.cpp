#include <iostream>
#include <queue>
using namespace std;

int n;
int r1, c1, r2, c2;
int dr[] = {-2, -2, 0, 0, 2, 2};
int dc[] = {-1, 1, -2, 2, -1, 1};
bool check[201][201];

int main() {
    int ans = -1;
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    queue<pair<pair<int, int>, int>> q;
    q.push({{r1, c1}, 0});
    check[r1][c1] = true;
    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        if (r == r2 && c == c2) {
            ans = t;
            break;
        }
        for (int i = 0; i < 6; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
            if (!check[nr][nc]) {
                check[nr][nc] = true;
                q.push({{nr, nc}, t + 1});
            }
        }
    }
    cout << ans << "\n";
}