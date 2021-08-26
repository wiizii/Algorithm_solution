#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    for (auto move : moves) {
        int col = move - 1;
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col]) {
                if (!s.empty() && s.top() == board[i][col]) {
                    answer += 2;
                    s.pop();
                } else
                    s.push(board[i][col]);
                board[i][col] = 0;
                break;
            }
        }
    }
    return answer;
}