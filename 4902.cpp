#include <bits/stdc++.h>
using namespace std;

const int INF = -0x3f3f3f3f;
int arr[410][810];
int dp[410][810];
int l;

int solve(int x, int y) {}

int main() {
    for (int t = 1; 1; t++) {
        cin >> l;
        if (l == 0) break;
        for (int i = 0; i < l; i++) {
            int acc = 0;
            for (int j = 0; j < i * 2 + 1; j++) {
                cin >> arr[i][j];
                acc += arr[i][j];
                dp[i][j] = acc;
            }
        }
        int answer = INF;
        answer = solve(0, 0);
        answer = max(answer, arr[1][1]);
        cout << t << ". " << answer << "\n";
    }
}