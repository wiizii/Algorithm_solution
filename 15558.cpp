#include <iostream>
#include <queue>
#include <string>
using namespace std;
const int MAX = 100001;
bool arr[2][MAX];
bool check[2][MAX];
struct pos {
    int i, j, t;
};

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < 2; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1')
                arr[i][j] = true;
            else
                arr[i][j] = false;
        }
    }
    queue<pos> q;
    q.push({0, 0, 0});
    check[0][0] = true;
    bool flag = false;
    while (!q.empty()) {
        int c = q.front().i;
        int r = q.front().j;
        int t = q.front().t;
        q.pop();
        if (r + 1 >= n || r + k >= n) {
            flag = true;
            break;
        }
        if (arr[c][r + 1] && t <= r && !check[c][r + 1]) {
            q.push({c, r + 1, t + 1});
            check[c][r + 1] = true;
        }
        if (r - 1 >= 0 && arr[c][r - 1] && t <= r && !check[c][r - 1]) {
            q.push({c, r - 1, t + 1});
            check[c][r - 1] = true;
        }
        if ((c & 1) && arr[c - 1][r + k] && t <= r && !check[c - 1][r + k]) {
            q.push({c - 1, r + k, t + 1});
            if (r + k < n) check[c - 1][r + k] = true;
        }
        if (!(c & 1) && arr[c + 1][r + k] && t <= r && !check[c + 1][r + k]) {
            q.push({c + 1, r + k, t + 1});
            if (r + k < n) check[c + 1][r + k] = true;
        }
    }
    if (flag)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}