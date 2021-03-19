#include <iostream>
using namespace std;

char board[16][16];
bool row[16][16], col[16][16], sec[4][4][16];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            cin >> board[i][j];
            if (board[i][j] != '-') {
                int c = board[i][j] - 'A';
                row[i][c] = true;
                col[j][c] = true;
                int x = i / 4;
                int y = j / 4;
                sec[x][y][c] = true;
            }
        }
    }
}
