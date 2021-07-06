#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int a, b, c, d, q, w;
    cin >> a >> b >> c >> d;
    q = a * d + b * c;
    w = b * d;
    int k = gcd(q, w);
    q /= k;
    w /= k;
    cout << q << " " << w << "\n";
}