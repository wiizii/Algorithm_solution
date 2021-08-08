#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int k = 0;
bool bo[103][103];
bool gi[103][103];

void draw_bo(int x, int y) {
    if ((bo[y][x - 1] && bo[y][x + 1]) || gi[y - 1][x] || gi[y - 1][x + 1])
        bo[y][x] = 1;
}
void draw_gi(int x, int y) {
    if (y == 0 || bo[y][x - 1] || bo[y][x] || (y > 0 && gi[y - 1][x]))
        gi[y][x] = 1;
}
void erase_bo(int x, int y) {
    bo[y][x] = 0;
    for (int i = 0; i <= k + 1; i++) {
        for (int j = 1; j <= k + 1; j++) {
            if (bo[j][i]) {
                if ((!bo[j][i - 1] || !bo[j][i + 1]) && !gi[j - 1][i] &&
                    !gi[j - 1][i + 1]) {
                    bo[y][x] = 1;
                    return;
                }
            }
            if (gi[j][i]) {
                if (!bo[j][i - 1] && !bo[j][i] && !gi[j - 1][i]) {
                    bo[y][x] = 1;
                    return;
                }
            }
        }
    }
}
void erase_gi(int x, int y) {
    gi[y][x] = 0;
    for (int i = 0; i <= k + 1; i++) {
        for (int j = 1; j <= k + 1; j++) {
            if (bo[j][i]) {
                if ((!bo[j][i - 1] || !bo[j][i + 1]) && !gi[j - 1][i] &&
                    !gi[j - 1][i + 1]) {
                    gi[y][x] = 1;
                    return;
                }
            }
            if (gi[j][i]) {
                if (!bo[j][i - 1] && !bo[j][i] && !gi[j - 1][i]) {
                    gi[y][x] = 1;
                    return;
                }
            }
        }
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    k = n;
    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        if (a && b)
            draw_bo(x + 1, y);
        else if (!a && b)
            draw_gi(x + 1, y);
        else if (a && !b)
            erase_bo(x + 1, y);
        else if (!a && !b)
            erase_gi(x + 1, y);
    }

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            vector<int> tmp1, tmp2;
            if (bo[j][i]) {
                tmp1.push_back(i - 1);
                tmp1.push_back(j);
                tmp1.push_back(1);
                answer.push_back(tmp1);
            }
            if (gi[j][i]) {
                tmp2.push_back(i - 1);
                tmp2.push_back(j);
                tmp2.push_back(0);
                answer.push_back(tmp2);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}