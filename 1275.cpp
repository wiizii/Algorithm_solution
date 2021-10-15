#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll init(vector<ll> &a, vector<ll> &tree, int node, int start, int end) {
    if (start == end)
        return tree[node] = a[start];
    else
        return tree[node] =
                   init(a, tree, node * 2, start, (start + end) / 2) +
                   init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

ll sum(vector<ll> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    return sum(tree, node * 2, start, (start + end) / 2, left, right) +
           sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<ll> &tree, int node, int start, int end, int index,
            ll diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(tree, node * 2, start, (start + end) / 2, index, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h + 1));
    vector<ll> tree(tree_size);
    for (int i = 0; i < n; i++) cin >> v[i];
    init(v, tree, 1, 0, n - 1);
    while (m--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
        cout << sum(tree, 1, 0, n - 1, x - 1, y - 1) << "\n";
        ll diff = b - v[a - 1];
        v[a - 1] = b;
        update(tree, 1, 0, n - 1, a - 1, diff);
    }
    return 0;
}
