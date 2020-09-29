#include <cstdio>
using namespace std;

int dp[1001] = {
    0, 1, 0, 1, 1,
};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 5; i <= n; i++) {
        if (dp[i - 1] + dp[i - 3] + dp[i - 4] == 3)
            dp[i] = 0;
        else
            dp[i] = 1;
    }
    dp[n] ? printf("SK\n") : printf("CY\n");
    return 0;
}