#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;

int main() {
    int n;
    int mul = 1;
    cin >> n;
    if (n <= 4) {
        cout << n << "\n";
        return 0;
    }
    while (n > 4) {
        n -= 3;
        mul = (mul * 3) % MOD;
    }
    if (n != 0) mul *= n;
    cout << mul % MOD << "\n";
}