#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;

int n;
int tree[10001][2];
int dep[10001];
int ind[10001];
int l[10001];
int r[10001];
int idx = 1;

void inorder(int node, int cnt) {
    if (tree[node][0] != -1) inorder(tree[node][0], cnt + 1);
    l[cnt] = min(l[cnt], idx);
    r[cnt] = max(r[cnt], ++idx);
    if (tree[node][1] != -1) inorder(tree[node][1], cnt + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u][0] = v;
        tree[u][1] = w;
        ind[v]++, ind[w]++;
    }

    for (int i = 1; i <= n; i++) l[i] = INF;

    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            root = i;
            break;
        }
    }
    inorder(root, 1);

    int ans_dep = 0;
    int ans_dist = 0;
    for (int i = 1; i <= n; i++) {
        if (ans_dist < r[i] - l[i]) {
            ans_dist = r[i] - l[i];
            ans_dep = i;
        }
    }
    cout << ans_dep << " " << ans_dist << "\n";
}