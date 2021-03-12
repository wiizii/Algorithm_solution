#include <cstdio>
using namespace std;

int board[9][9];
bool flag = false;

void print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d", board[i][j]);
        }
        printf("\n");
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
        for (int i = 1; i <= 9; i++) {
            if (isPossible(x, y, i)) {
                board[x][y] = i;
                solve(n + 1);
                if (flag) return;
                board[x][y] = 0;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) scanf("%1d", &board[i][j]);
    solve(0);
    return 0;
}