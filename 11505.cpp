#include <cstdio>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;
const ll MOD = 1000000007;

ll init(vector<ll>& a, vector<ll>& tree, int node, int start, int end) {
    if (start == end)
        return tree[node] = a[start];
    else
        return tree[node] = ((init(a, tree, node * 2, start, (start + end) / 2))%MOD * (init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end))%MOD)%MOD;
}

ll multi(vector<ll>& tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return 1;
    if (left <= start && end <= right)
        return tree[node];
    return (multi(tree, node * 2, start, (start + end) / 2, left, right) * multi(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right))%MOD;
}

ll update(vector<ll>& tree, int node, int start, int end, int index, ll diff) {
    if (!(start <= index && index <= end))
        return tree[node];
    if (start == end)
        return tree[node] = diff;

    return tree[node] = (update(tree, node * 2, start, (start + end) / 2, index,diff) * update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index,diff)) % MOD;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<ll> a(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h + 1));
    vector<ll> tree(tree_size);
    m += k;
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    init(a, tree, 1, 0, n - 1);
    while (m--) {
        int t1;
        scanf("%d",&t1);
        if (t1 == 1) {
            int t2;
            ll t3;
            scanf("%d %lld", &t2, &t3);
            update(tree, 1, 0, n - 1, t2-1, t3);
        }
        else if (t1 == 2) {
            int t2, t3;
            scanf("%d %d", &t2, &t3);
            printf("%lld\n", multi(tree, 1, 0, n - 1, t2 - 1, t3 - 1)%MOD);
        }
    }
    return 0;
}