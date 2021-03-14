#include <iostream>
#include <queue>
#include <vector>
using namespace std;
char board[8][8];
bool check[8][8];
vector<pair<int, int>> wall;

void wall_move() {
    for (int i = 0; i < wall.size(); i++) {
        int &x = wall[i].first;
        int &y = wall[i].second;
        if (x < 8) {
            board[x][y] = '.';
            x++;
            if (x != 8) board[x][y] = '#';
        }
    }
}

void print() {
    cout << "\n";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
            if (board[i][j] == '#') wall.push_back({i, j});
        }
    }
    queue<pair<int, int>> q;
    q.push({7, 0});
    check[7][0] = true;
    while (!q.empty()) {
        }
}