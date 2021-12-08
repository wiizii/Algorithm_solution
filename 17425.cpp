#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 1000001;

ll dp[MAX] = {0, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i < MAX; i++) {
        for (int j = 1; j * i < MAX; j++) {
            dp[i * j] += i;
        }
        dp[i] += (dp[i - 1] + 1);
    }

    int n;
    cin >> n;
    cout << dp[n] << "\n";
}