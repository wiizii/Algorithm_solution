#include <iostream>
using namespace std;

int dp[46][2];

int main() {
    int k;
    cin >> k;
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
    }
    cout << dp[k][0] << " " << dp[k][1] << "\n";
}