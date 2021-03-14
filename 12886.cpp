#include <iostream>
#include <queue>
using namespace std;

bool check[2001][2001];

struct stone {
    int a, b, c;
};

int main() {
    int a, b, c;
    bool flag = false;
    cin >> a >> b >> c;
    check[a][b] = true;
    check[b][a] = true;
    check[b][c] = true;
    check[c][b] = true;
    check[a][c] = true;
    check[c][a] = true;
    queue<stone> q;
    q.push({a, b, c});
    while (!q.empty()) {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if (a == b && b == c) {
            flag = true;
            break;
        }
        if (a < b) {
            int small = a + a;
            int big = b - a;
            if (!check[small][big]) {
                check[small][big] = true;
                q.push({small, big, c});
            }
        }
        if (a > b) {
            int small = b + b;
            int big = a - b;
            if (!check[big][small]) {
                check[big][small] = true;
                q.push({big, small, c});
            }
        }
        if (a < c) {
            int small = a + a;
            int big = c - a;
            if (!check[small][big]) {
                check[small][big] = true;
                q.push({small, b, big});
            }
        }
        if (a > c) {
            int small = c + c;
            int big = a - c;
            if (!check[big][small]) {
                check[big][small] = true;
                q.push({big, b, small});
            }
        }
        if (b < c) {
            int small = b + b;
            int big = c - b;
            if (!check[small][big]) {
                check[small][big] = true;
                q.push({a, small, big});
            }
        }
        if (b > c) {
            int small = c + c;
            int big = b - c;
            if (!check[big][small]) {
                check[big][small] = true;
                q.push({a, big, small});
            }
        }
    }
    if (flag)
        cout << "1\n";
    else
        cout << "0\n";
}