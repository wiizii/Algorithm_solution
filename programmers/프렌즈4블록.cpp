#include <iostream>
#include <string>
#include <vector>

using namespace std;

int remove(const int &m, const int &n, vector<string> &board) {
    int num = 0;
    bool check[30][30] = {
        0,
    };
    for (int i = 0; i < m - 1; i++)
        for (int j = 0; j < n - 1; j++)
            if (board[i][j] != '0' && board[i][j] == board[i + 1][j] &&
                board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i + 1][j + 1])
                check[i][j] = check[i + 1][j] = check[i][j + 1] =
                    check[i + 1][j + 1] = 1;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (check[i][j]) board[i][j] = '0', num++;

    for (int j = 0; j < n; j++) {
        for (int i = m - 1; i >= 0; i--) {
            if (board[i][j] != '0') {
                int k = i;
                while (1) {
                    if (k + 1 == m || board[k + 1][j] != '0') break;
                    board[k + 1][j] = board[k][j];
                    board[k][j] = '0';
                    k++;
                }
            }
        }
    }
    return num;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while (1) {
        int rblock = remove(m, n, board);
        if (rblock)
            answer += rblock;
        else
            break;
    }
    return answer;
}