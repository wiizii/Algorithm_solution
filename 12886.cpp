#include <iostream>
#include <queue>
#include <set>
using namespace std;

bool check[1001][1001][1001];

struct stone {
    int a, b, c;
};
set<stone> s;

int main() {
    int a, b, c;
    bool flag = false;
    cin >> a >> b >> c;
    check[a][b][c] = true;
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
            if (!check[small][big][c]) {
                check[small][big][c] = true;
                q.push({small, big, c});
            }
        }
        if (a > b) {
            int small = b + b;
            int big = a - b;
            if (!check[big][small][c]) {
                check[big][small][c] = true;
                q.push({big, small, c});
            }
        }
        if (a < c) {
            int small = a + a;
            int big = c - a;
            if (!check[small][b][big]) {
                check[small][b][big] = true;
                q.push({small, b, big});
            }
        }
        if (a > c) {
            int small = c + c;
            int big = a - c;
            if (!check[big][b][small]) {
                check[big][b][small] = true;
                q.push({big, b, small});
            }
        }
        if (b < c) {
            int small = b + b;
            int big = c - b;
            if (!check[a][small][big]) {
                check[a][small][big] = true;
                q.push({a, small, big});
            }
        }
        if (b > c) {
            int small = c + c;
            int big = b - c;
            if (!check[a][big][small]) {
                check[a][big][small] = true;
                q.push({a, big, small});
            }
        }
    }
    if (flag)
        cout << "1\n";
    else
        cout << "0\n";
}