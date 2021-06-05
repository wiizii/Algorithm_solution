#include <algorithm>
#include <iostream>
using namespace std;

int map[1001][1001];
int d[1001][1001][3];
int check[1001][1001];
int n, m;
const int INF = -0x3f3f3f3f;

int max3(int a, int b, int c) { return max(a, max(b, c)); }

int solve(int dir, int row, int col) {
    if (row == n && col == m) return map[row][col];
    int &result = d[row][col][dir];
    if (result != INF) return result;
    check[row][col] = true;
    int a, b, c;
    a = b = c = INF;
    if (col - 1 >= 1 && !check[row][col - 1]) a = solve(0, row, col - 1);
    if (col + 1 <= m && !check[row][col + 1]) b = solve(1, row, col + 1);
    if (row + 1 <= n && !check[row + 1][col]) c = solve(2, row + 1, col);
    check[row][col] = false;
    return result = map[row][col] + max3(a, b, c);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            d[i][j][0] = d[i][j][1] = d[i][j][2] = INF;
        }
    cout << solve(1, 1, 1) << "\n";
    return 0;
}