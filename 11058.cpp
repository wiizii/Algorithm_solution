#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;

ll dp[101];

int main() {
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    int n;
    cin >> n;
    for (int i = 6; i <= n; i++) {
        dp[i] =
            max({dp[i - 1] + 1, dp[i - 3] * 2, dp[i - 4] * 3, dp[i - 5] * 4});
    }
    cout << dp[n] << "\n";
}
// test