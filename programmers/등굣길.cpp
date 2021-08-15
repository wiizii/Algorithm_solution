#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int mod = 1000000007;

int map[101][101];
int dp[101][101];

int solve(int m, int n) {
    if (m == 1 && n == 1) return 1;
    if (map[m][n] == -1) return 0;
    if (dp[m][n]) return dp[m][n];
    if (m == 1) {
        dp[m][n] += solve(m, n - 1) % mod;
    } else if (n == 1) {
        dp[m][n] += solve(m - 1, n) % mod;
    } else {
        dp[m][n] += solve(m - 1, n) % mod;
        dp[m][n] += solve(m, n - 1) % mod;
    }
    return dp[m][n] % mod;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for (vector<int> &k : puddles) {
        int r = k[0];
        int c = k[1];
        map[r][c] = -1;
    }
    answer = solve(m, n);
    return answer;
}