#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

vector<vector<int>> dp(MAX + 1, vector<int>(4, 0));

int max3(int a, int b, int c) { return max(a, max(b, c)); }

int solution(vector<vector<int>> land) {
    int answer = 0;
    dp[0] = land[0];
    for (int i = 1; i < land.size(); i++) {
        dp[i][0] = land[i][0] + max3(dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]);
        dp[i][1] = land[i][1] + max3(dp[i - 1][0], dp[i - 1][2], dp[i - 1][3]);
        dp[i][2] = land[i][2] + max3(dp[i - 1][0], dp[i - 1][1], dp[i - 1][3]);
        dp[i][3] = land[i][3] + max3(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);
    }

    for (int i = 0; i < 4; i++) answer = max(answer, dp[land.size() - 1][i]);
    return answer;
}