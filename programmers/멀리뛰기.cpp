#include <string>
#include <vector>

using namespace std;
const int MAX = 2001;
const int mod = 1234567;

long long dp[MAX] = {0, 1, 2};

int solve(int n) {
    if (dp[n]) return dp[n];
    return dp[n] = (solve(n - 1) + solve(n - 2)) % mod;
}

long long solution(int n) {
    long long answer = 0;
    answer = solve(n);
    return answer;
}