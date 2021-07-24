#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 0x3f3f3f3f;

ll min_init(vector<ll> &v, vector<ll> &tree, int node, int left, int right) {
    if (left == right) return tree[node] = v[left];
    int mid = (left + right) / 2;
    int leftMin = min_init(v, tree, node * 2, left, mid);
    int rightMin = min_init(v, tree, node * 2 + 1, mid + 1, right);
    return tree[node] = min(leftMin, rightMin);
}

ll getMinValue(vector<ll> &tree, int node, int left, int right, int treeLeft,
               int treeRight) {
    if (right < treeLeft || treeRight < left) return INF;
    if (left <= treeLeft && treeRight <= right) return tree[node];
    int mid = (treeLeft + treeRight) / 2;
    return min(
        getMinValue(tree, node * 2, left, right, treeLeft, mid),
        getMinValue(tree, node * 2 + 1, left, right, mid + 1, treeRight));
}

ll max_init(vector<ll> &v, vector<ll> &tree, int node, int left, int right) {
    if (left == right) return tree[node] = v[left];
    int mid = (left + right) / 2;
    int leftMax = max_init(v, tree, node * 2, left, mid);
    int rightMax = max_init(v, tree, node * 2 + 1, mid + 1, right);
    return tree[node] = max(leftMax, rightMax);
}

ll getMaxValue(vector<ll> &tree, int node, int left, int right, int treeLeft,
               int treeRight) {
    if (right < treeLeft || treeRight < left) return 0;
    if (left <= treeLeft && treeRight <= right) return tree[node];
    int mid = (treeLeft + treeRight) / 2;
    return max(
        getMaxValue(tree, node * 2, left, right, treeLeft, mid),
        getMaxValue(tree, node * 2 + 1, left, right, mid + 1, treeRight));
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
    vector<ll> max_tree(tree_size), min_tree(tree_size);
    min_init(v, min_tree, 1, 0, n - 1);
    max_init(v, max_tree, 1, 0, n - 1);
    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << getMinValue(min_tree, 1, x - 1, y - 1, 0, n - 1) << " "
             << getMaxValue(max_tree, 1, x - 1, y - 1, 0, n - 1) << "\n";
    }
}