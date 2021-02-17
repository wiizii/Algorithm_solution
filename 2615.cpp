#include <iostream>
using namespace std;

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int board[20][20];

int main() {
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++) cin >> board[i][j];
    for (int j = 0; j < 19; j++) {
        for (int i = 0; i < 19; i++) {
            if (board[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    int cnt = 0;
                    int nx = i;
                    int ny = j;
                    while (nx >= 0 && nx < 19 && ny >= 0 && ny < 19 &&
                           board[nx][ny] == 1) {
                        cnt++;
                        nx += dx[k];
                        ny += dy[k];
                    }
                    nx = i;
                    ny = j;
                    while (nx >= 0 && nx < 19 && ny >= 0 && ny < 19 &&
                           board[nx][ny] == 1) {
                        cnt++;
                        nx += dx[k + 4];
                        ny += dy[k + 4];
                    }
                    if (cnt - 1 == 5) {
                        cout << 1 << "\n" << i + 1 << " " << j + 1 << "\n";
                        return 0;
                    }
                }
            }
            if (board[i][j] == 2) {
                for (int k = 0; k < 4; k++) {
                    int cnt = 0;
                    int nx = i;
                    int ny = j;
                    while (nx >= 0 && nx < 19 && ny >= 0 && ny < 19 &&
                           board[nx][ny] == 2) {
                        cnt++;
                        nx += dx[k];
                        ny += dy[k];
                    }
                    nx = i;
                    ny = j;
                    while (nx >= 0 && nx < 19 && ny >= 0 && ny < 19 &&
                           board[nx][ny] == 2) {
                        cnt++;
                        nx += dx[k + 4];
                        ny += dy[k + 4];
                    }
                    if (cnt - 1 == 5) {
                        cout << 2 << "\n" << i + 1 << " " << j + 1 << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << 0 << "\n";
}