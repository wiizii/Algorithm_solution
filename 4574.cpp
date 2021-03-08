#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int board[9][9];
bool check[10][10];
int dx[2] = {1, 0};
int dy[2] = {0, 1};
bool flag = false;

void print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

bool isPossible(int x, int y, int n) {
    for (int i = 0; i < 9; i++) {
        if (board[i][y] == n) return false;
        if (board[x][i] == n) return false;
    }
    int r = (x / 3) * 3;
    int c = (y / 3) * 3;
    for (int i = r; i < r + 3; i++)
        for (int j = c; j < c + 3; j++)
            if (board[i][j] == n) return false;
    return true;
}

void solve(int n) {
    if (n == 81) {
        print();
        flag = true;
        return;
    }
    int x = n / 9, y = n % 9;
    if (board[x][y] != 0) {
        solve(n + 1);
    } else {
        for (int k = 0; k < 2; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 9 || ny >= 9) continue;
            if (board[nx][ny] != 0) continue;
            for (int i = 1; i <= 9; i++) {
                for (int j = 1; j <= 9; j++) {
                    if (i != j && !check[i][j] && !check[j][i] &&
                        isPossible(x, y, i) && isPossible(nx, ny, j)) {
                        check[i][j] = true;
                        check[j][i] = true;
                        board[x][y] = i;
                        board[nx][ny] = j;
                        if (!flag) solve(n + 1);
                        board[x][y] = 0;
                        board[nx][ny] = 0;
                        check[i][j] = false;
                        check[j][i] = false;
                    }
                }
            }
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
        memset(check, 0, sizeof(check));
        flag = false;
        for (int i = 0; i < n; i++) {
            int x;
            int a, b;
            string s;
            cin >> x >> s;
            a = x;
            board[s[0] - 'A'][s[1] - '1'] = x;
            cin >> x >> s;
            b = x;
            board[s[0] - 'A'][s[1] - '1'] = x;
            check[a][b] = check[b][a] = true;
        }
        for (int i = 1; i <= 9; i++) {
            string s;
            cin >> s;
            board[s[0] - 'A'][s[1] - '1'] = i;
        }
        cout << "Puzzle " << t << "\n";
        solve(0);
    }
    return 0;
}