#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 0x3f3f3f3f;

ll init(vector<ll> &v, vector<ll> &tree, int node, int left, int right) {
    if (left == right) return tree[node] = v[left];
    int mid = (left + right) / 2;
    int leftMin = init(v, tree, node * 2, left, mid);
    int rightMin = init(v, tree, node * 2 + 1, mid + 1, right);
    return tree[node] = min(leftMin, rightMin);
}

ll query(vector<ll> &tree, int node, int left, int right, int treeLeft,
         int treeRight) {
    if (right < treeLeft || treeRight < left) return INF;
    if (left <= treeLeft && treeRight <= right) return tree[node];
    int mid = (treeLeft + treeRight) / 2;
    return min(query(tree, node * 2, left, right, treeLeft, mid),
               query(tree, node * 2 + 1, left, right, mid + 1, treeRight));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h + 1));
    vector<ll> tree(tree_size);
    init(v, tree, 1, 0, n - 1);
    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << query(tree, 1, x - 1, y - 1, 0, n - 1) << "\n";
    }
}