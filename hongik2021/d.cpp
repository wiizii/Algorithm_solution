#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        ll cnt = 0;
        while (n) {
            n /= 2;
            cnt++;
        }
        cout << cnt + m << '\n';
    }
}