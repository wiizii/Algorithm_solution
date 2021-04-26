#include <bits/stdc++.h>
using namespace std;

int check[1000002];
int f, s, g, u, d;
queue<int> q;

int bfs() {
    int ret = -1;
    q.push(s);
    check[s] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == g) {
            ret = check[x];
            break;
        }
        if (x + u <= f && check[x + u] == -1) {
            check[x + u] = check[x] + 1;
            q.push(x + u);
        }
        if (x - d >= 1 && check[x - d] == -1) {
            check[x - d] = check[x] + 1;
            q.push(x - d);
        }
    }
    return ret;
}

int main() {
    memset(check, -1, sizeof(check));
    cin >> f >> s >> g >> u >> d;
    int answer = bfs();
    if (answer == -1)
        cout << "use the stairs\n";
    else
        cout << answer << "\n";
}