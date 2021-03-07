#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int board[10][10];
bool flag = false;
int hole = 0;

void print() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isPossible(int x, int y, int n) {
    for (int i = 1; i <= 9; i++) {
        if (board[i][y] == n) return false;
        if (board[x][i] == n) return false;
    }
    int r = ((x - 1) / 3) * 3 + 1;
    int c = ((y - 1) / 3) * 3 + 1;
    for (int i = r; i < r + 3; i++)
        for (int j = c; j < c + 3; j++)
            if (board[i][j] == n) return false;
    return true;
}

void solve(int x, int y, int cnt) {
    if (flag) return;
    if (cnt == hole) {
        flag = true;
        return;
    }
    if (board[x][y]) {
        solve(x + 1, y, cnt);
        solve(x, y + 1, cnt);
    } else
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                if (i + 1 < 10 && !board[i][j] && !board[i + 1][j]) {
                    for (int k = 1; k <= 9; k++) {
                        for (int l = 1; l <= 9; l++) {
                            if (k != l && isPossible(i, j, k) &&
                                isPossible(i + 1, j, l)) {
                                board[i][j] = k;
                                board[i + 1][j] = l;
                                solve(cnt + 2);
                                if (flag) {
                                    return;
                                }
                                board[i][j] = 0;
                                board[i + 1][j] = 0;
                            }
                        }
                    }
                }
                if (j + 1 < 10 && !board[i][j] && !board[i][j + 1]) {
                    for (int k = 1; k <= 9; k++) {
                        for (int l = 1; l <= 9; l++) {
                            if (k != l && isPossible(i, j, k) &&
                                isPossible(i, j + 1, l)) {
                                board[i][j] = k;
                                board[i][j + 1] = l;
                                solve(cnt + 2);
                                if (flag) {
                                    return;
                                }
                                board[i][j] = 0;
                                board[i][j + 1] = 0;
                            }
                        }
                    }
                }
                if ((i + 1 < 10 && !board[i][j] && board[i + 1][j]) ||
                    (j + 1 < 10 && !board[i][j] && board[i][j + 1]))
                    return;
            }
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 0;
    while (++t) {
        int n;
        cin >> n;
        if (n == 0) break;
        memset(board, 0, sizeof(board));
        hole = 72 - 2 * n;
        flag = false;
        for (int i = 0; i < n; i++) {
            int x;
            string s;
            cin >> x >> s;
            board[s[0] - 'A' + 1][s[1] - '0'] = x;
            cin >> x >> s;
            board[s[0] - 'A' + 1][s[1] - '0'] = x;
        }
        for (int i = 1; i <= 9; i++) {
            string s;
            cin >> s;
            board[s[0] - 'A' + 1][s[1] - '0'] = i;
        }
        solve(0, 0, 0);
        cout << "Puzzle " << t << "\n";
        print();
    }
    return 0;
}
// test