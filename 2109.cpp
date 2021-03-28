#include <algorithm>
#include <iostream>
using namespace std;

struct info {
    int p, d;
};

bool cmp(const info &a, const info &b) {
    if (a.d > b.d)
        return true;
    else if (a.d == b.d) {
        return a.p > b.p;
    } else
        return false;
}

info f[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> f[i].p >> f[i].d;
    sort(f, f + n, cmp);
    int ans = 0;
    int sf = 0;
    int day = f[sf].d;
    while (sf < n && day > 0) {
    }

    cout << ans << "\n";
}