#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v(100001, 0);

int main() {
    cin >> n >> k;
    int ans = 0;
    int acc = 0;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < k; i++) acc += v[i];
    ans = acc;
    int l = 0, r = k - 1;
    while (r < n) {
        ans = max(ans, acc);
        acc += v[++r];
        acc -= v[l++];
    }
    cout << ans << "\n";
}