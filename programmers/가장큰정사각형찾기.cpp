#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int min3(int a, int b, int c) { return min(a, min(b, c)); }

int solution(vector<vector<int>> board) {
    int answer = 0;
    int r = board.size();
    int c = board[0].size();
    vector<vector<int>> dp(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 1) {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] =
                        min3(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
                answer = max(answer, dp[i][j]);
            }
        }
    }

    return answer * answer;
}