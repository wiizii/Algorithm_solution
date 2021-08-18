#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
int dp[201][201];

int solve(int x, int y) {
    int &ret = dp[x][y];
    if (ret) return ret;
    if (x == y) return 0;
    if (x + 1 == y) return v[x][0] * v[x][1] * v[y][1];
    ret = -1;
    for (int i = x; i <= y - 1; i++) {
        int a = solve(x, i);
        int b = solve(i + 1, y);
        if (ret == -1 || ret > a + b + v[x][0] * v[i][1] * v[y][1])
            ret = a + b + v[x][0] * v[i][1] * v[y][1];
    }
    return ret;
}

int solution(vector<vector<int>> matrix_sizes) {
    v = matrix_sizes;
    return solve(0, v.size() - 1);
}