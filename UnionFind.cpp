#include <algorithm>
#include <iostream>
using namespace std;

int parent[1000001];

int Find(int x) {
    if (x == parent[x])
        return x;
    else
        return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x != y) parent[y] = x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int op, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) parent[i] = i;
    while (m--) {
        cin >> op >> a >> b;
        if (op == 0)
            Union(a, b);
        else if (op == 1) {
            int a_parent = Find(a);
            int b_parent = Find(b);

            if (a_parent == b_parent)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
