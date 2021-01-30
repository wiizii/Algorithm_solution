#include <iostream>
#include <queue>
#include <set>
using namespace std;

struct water {
    int a, b, c;
};
bool check[201][201][201];
int A, B, C;

int main() {
    set<int> s;
    cin >> A >> B >> C;
    s.insert(C);
    check[0][0][C] = true;
    queue<water> q;
    q.push({0, 0, C});
    while (!q.empty()) {
        water cur = q.front();
        q.pop();
        if (cur.a == 0) s.insert(cur.c);
        if (cur.a > 0) {
            int nexta = 0;
            int nextb = cur.a + cur.b;
            if (nextb > B) {
                nexta = nextb - B;
                nextb = B;
            }
            if (!check[nexta][nextb][cur.c]) {
                check[nexta][nextb][cur.c] = true;
                q.push({nexta, nextb, cur.c});
            }
            nexta = 0;
            int nextc = cur.a + cur.c;
            if (nextc > C) {
                nexta = nextc - C;
                nextc = C;
            }
            if (!check[nexta][cur.b][nextc]) {
                check[nexta][cur.b][nextc] = true;
                q.push({nexta, cur.b, nextc});
            }
        }
        if (cur.b > 0) {
            int nextb = 0;
            int nexta = cur.b + cur.a;
            if (nexta > A) {
                nextb = nexta - A;
                nexta = A;
            }
            if (!check[nexta][nextb][cur.c]) {
                check[nexta][nextb][cur.c] = true;
                q.push({nexta, nextb, cur.c});
            }
            nextb = 0;
            int nextc = cur.b + cur.c;
            if (nextc > C) {
                nextb = nextc - C;
                nextc = C;
            }
            if (!check[cur.a][nextb][nextc]) {
                check[cur.a][nextb][nextc] = true;
                q.push({cur.a, nextb, nextc});
            }
        }
        if (cur.c > 0) {
            int nextc = 0;
            int nexta = cur.a + cur.c;
            if (nexta > A) {
                nextc = nexta - A;
                nexta = A;
            }
            if (!check[nexta][cur.b][nextc]) {
                check[nexta][cur.b][nextc] = true;
                q.push({nexta, cur.b, nextc});
            }
            nextc = 0;
            int nextb = cur.b + cur.c;
            if (nextb > B) {
                nextc = nextb - B;
                nextb = B;
            }
            if (!check[cur.a][nextb][nextc]) {
                check[cur.a][nextb][nextc] = true;
                q.push({cur.a, nextb, nextc});
            }
        }
    }
    for (auto i = s.begin(); i != s.end(); i++) {
        cout << *i << " ";
    }
}