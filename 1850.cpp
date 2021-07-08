#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll k = gcd(a, b);
    for (int i = 0; i < k; i++) cout << 1;
}