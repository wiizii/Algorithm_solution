#include <cstring>
#include <iostream>
using namespace std;

int tree[10001];
int dep[10001];

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(tree, -1, sizeof(tree));
        memset(dep, 0, sizeof(dep));
        int n;
        int node1, node2;
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            int p, c;
            cin >> p >> c;
            tree[c] = p;
        }
        cin >> node1 >> node2;
        for (int i = 1; i <= n; i++) {
            int cur = tree[i];
            while (cur != -1) {
                dep[i]++;
                cur = tree[cur];
            }
        }
        while (1) {
            if (dep[node1] == dep[node2]) {
                if (node1 == node2) {
                    cout << node1 << "\n";
                    break;
                } else {
                    node1 = tree[node1];
                    node2 = tree[node2];
                }
            } else if (dep[node1] < dep[node2])
                node2 = tree[node2];
            else if (dep[node1] > dep[node2])
                node1 = tree[node1];
        }
    }
}