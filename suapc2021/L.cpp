#include <algorithm>
#include <iostream>
using namespace std;

int n;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char arr[2001][2001];
bool check[2001][2001];
int max_bomb = 0;

void draw_bomb(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x;
        int ny = y;
        while (nx + dx[i] >= 0 && ny + dy[i] >= 0 && nx + dx[i] < n &&
               ny + dy[i] < n) {
            nx += dx[i];
            ny += dy[i];
            if (arr[nx][ny] != '.') break;
            check[nx][ny] = true;
        }
    }
}

void erase_bomb(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x;
        int ny = y;
        while (nx + dx[i] >= 0 && ny + dy[i] >= 0 && nx + dx[i] < n &&
               ny + dy[i] < n) {
            nx += dx[i];
            ny += dy[i];
            if (arr[nx][ny] != '.') break;
            check[nx][ny] = 0;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j] == 'X') draw_bomb(i, j);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j] == 'O') erase_bomb(i, j);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check[i][j])
                cout << 'B';
            else
                cout << arr[i][j];
        }
        cout << "\n";
    }
}