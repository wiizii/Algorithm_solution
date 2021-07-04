#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll s;
    cin >> s;
    ll cnt = 1;
    while (1) {
        if (s - cnt <= cnt) break;
        s -= cnt;
        cnt++;
    }
    cout << cnt << "\n";
}