#include <iostream>
#include <string>
#include <vector>

using namespace std;

int map[100][100];
int n, m;
bool flag = false;

void rotate(vector<vector<int>> &v) {
    int size = v.size();
    vector<vector<int>> tmp(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) tmp[size - j - 1][i] = v[i][j];
    v = tmp;
}

bool isKey() {
    for (int i = m - 1; i < m - 1 + n; i++)
        for (int j = m - 1; j < m - 1 + n; j++)
            if (map[i][j] != 1) return false;
    return true;
}

void draw(int starti, int startj, vector<vector<int>> &key) {
    for (int i = starti; i < starti + m; i++)
        for (int j = startj; j < startj + m; j++)
            map[i][j] += key[i - starti][j - startj];
}
void undraw(int starti, int startj, vector<vector<int>> &key) {
    for (int i = starti; i < starti + m; i++)
        for (int j = startj; j < startj + m; j++)
            map[i][j] -= key[i - starti][j - startj];
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    n = lock.size();
    m = key.size();
    for (int i = m - 1; i < m - 1 + n; i++)
        for (int j = m - 1; j < m - 1 + n; j++)
            map[i][j] = lock[i - m + 1][j - m + 1];
    for (int r = 0; r < 4; r++) {
        rotate(key);
        for (int i = 0; i < n + m; i++) {
            for (int j = 0; j < n + m; j++) {
                draw(i, j, key);
                if (isKey()) return true;
                undraw(i, j, key);
            }
        }
    }

    return false;
}