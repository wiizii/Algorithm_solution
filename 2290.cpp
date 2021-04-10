#include <bits/stdc++.h>
using namespace std;

int s;
string n;
char arr[40][200];

void draw(int x, int y, int n) {
    for (int i = x; i < x + (s * 2) + 3; i++) {
        for (int j = y; j <= y + s + 2; j++) {
            arr[i][j] = ' ';
        }
    }
    if (n == 2 || n == 3 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9 ||
        n == 0) {
        for (int i = y + 1; i <= y + s; i++) arr[x][i] = '-';
    }
    if (n == 1 || n == 2 || n == 3 || n == 4 || n == 7 || n == 8 || n == 9 ||
        n == 0) {
        for (int i = x + 1; i <= x + s; i++) arr[i][y + s + 1] = '|';
    }
    if (n == 4 || n == 5 || n == 6 || n == 8 || n == 9 || n == 0) {
        for (int i = x + 1; i <= x + s; i++) arr[i][y] = '|';
    }
    if (n == 2 || n == 3 || n == 4 || n == 5 || n == 6 || n == 8 || n == 9) {
        for (int i = y + 1; i <= y + s; i++) arr[x + s + 1][i] = '-';
    }
    if (n == 1 || n == 3 || n == 4 || n == 5 || n == 6 || n == 7 || n == 8 ||
        n == 9 || n == 0) {
        for (int i = x + s + 2; i <= x + (2 * s) + 1; i++)
            arr[i][y + s + 1] = '|';
    }
    if (n == 2 || n == 6 || n == 8 || n == 0) {
        for (int i = x + s + 2; i <= x + (2 * s) + 1; i++) arr[i][y] = '|';
    }
    if (n == 2 || n == 3 || n == 5 || n == 6 || n == 8 || n == 9 || n == 0) {
        for (int i = y + 1; i <= y + s; i++) arr[x + (2 * s) + 2][i] = '-';
    }
}

int main() {
    cin >> s >> n;
    draw(0, 0, 1);
    for (int i = 0; i < n.size(); i++) draw(0, (i * (s + 3)), n[i] - '0');
    for (int i = 0; i < (s * 2) + 3; i++) {
        for (int j = 0; j < (s + 3) * n.size(); j++) cout << arr[i][j];
        cout << "\n";
    }
}