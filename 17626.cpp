#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dp[50001] = {
    0,
    1,
};
vector<int> square;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i * i <= 50000; i++) {
        square.push_back(i * i);
    }
    for (int i = 2; i <= n; i++) {
        int min_num = 0x3f3f3f3f;
        for (int j = 0; square[j] <= i; j++) {
            int tmp = i - square[j];
            min_num = min(min_num, dp[tmp]);
        }
        dp[i] = min_num + 1;
    }

    cout << dp[n] << "\n";
    return 0;
}