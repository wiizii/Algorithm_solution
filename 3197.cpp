#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char map[1500][1500];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r, c;
    bool flag = false;
    queue<pair<int, int>> A, B;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
            if (flag == false && map[i][j] == 'L') {
                map[i][j] = 'A';
                A.push({i, j});
                flag = true;
            }
            if (flag == true && map[i][j] == 'L') {
                map[i][j] = 'B';
                B.push({i, j});
            }
        }
    }


    return 0;
}