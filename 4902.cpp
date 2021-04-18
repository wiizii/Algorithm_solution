#include <bits/stdc++.h>
using namespace std;

int arr[410][810];
int dp[410][810];
int l;

int solve_up(int x, int y) {
    int &ret = dp[x][y];
    if (ret != -0x3f3f3f3f) return ret;
    if (x >= 3) return ret;
    int acc = 0;
    for (int i = x; i < l; i++) {
        for (int j = y; j < i * 2 + 1; j++) acc += arr[i][j];
        ret = max(ret, acc);
    }
    ret = max({ret, solve(x + 1, y), solve(x + 1, y + 2)});
    return ret;
}

int solve_down(int x, int y) {
    int &ret = dp[x][y];
    if (ret != -0x3f3f3f3f) return ret;
    if (x == 0) return -0x3f3f3f3f;
    int acc = 0;
    for (int j = y; j < x * 2 + 1; j += 2) {
        if (j - 2 < 0) continue;
        for (int i = y; j < i * 2) }
}

int main() {
    for (int t = 1; 1; t++) {
        cin >> l;
        if (l == 0) break;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < i * 2 + 1; j++) {
                cin >> arr[i][j];
                dp[i][j] = -0x3f3f3f3f;
            }
        }
        cout << t << ". " << max(solve_up(0, 0), solve_down(l - 1, 1)) << "\n";
    }
}