#include <bits/stdc++.h>
using namespace std;

const int INF = -0x3f3f3f3f;
int arr[410][810];
int dp[410][810];
int l;

int solve_up(int x, int y) {
    int &ret = dp[x][y];
    if (ret != INF) return ret;
    ret = arr[x][y];
    if (y >= 0 && y + 2 < (x + 1) * 2 + 1) {
        ret += solve_up(x + 1, y);
        ret += solve_up(x + 1, y + 2);
        ret += arr[x + 1][y + 1];
    }
    if (x + 2 < l && 0 <= y && y + 4 < (x + 2) * 2 + 1)
        ret -= solve_up(x + 2, y + 2);
    return ret;
}

int solve_down(int x, int y) {
    int &ret = dp[x][y];
    if (ret != INF) return ret;
    ret = arr[x][y];
    if (y - 2 >= 1 && y < (x - 1) * 2 + 1) {
        ret += solve_down(x - 1, y - 2);
        ret += solve_down(x - 1, y);
        ret += arr[x - 1][y - 1];
    }
    if (x - 2 >= 1 && y - 4 >= 0 && y < (x - 2) * 2 + 1)
        ret -= solve_down(x - 2, y - 2);
    return ret;
}

int main() {
    for (int t = 1; 1; t++) {
        cin >> l;
        if (l == 0) break;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < i * 2 + 1; j++) {
                cin >> arr[i][j];
                dp[i][j] = INF;
            }
        }
        int answer = INF;
        solve_up(0, 0);
        for (int i = 1; i < (l - 1) * 2 + 1; i += 2) {
            solve_down(l - 1, i);
        }
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < i * 2 + 1; j++) {
                answer = max(answer, dp[i][j]);
            }
        }

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < i * 2 + 1; j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }

        answer = max(answer, arr[1][1]);
        cout << t << ". " << answer << "\n";
    }
}