#include <iostream>
using namespace std;

int map[101][101];

void draw(int x1, int y1, int x2, int y2) {
    for (int i = x1; i < x2; i++)
        for (int j = y1; j < y2; j++) map[i][j] = 1;
}

int find() {
    int cnt = 0;
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            if (map[i][j]) cnt++;
    return cnt;
}

int main() {
    int x1, x2, y1, y2;
    int answer = 0;
    for (int i = 0; i < 4; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        draw(y1, x1, y2, x2);
    }
    cout << find() << "\n";
    return 0;
}