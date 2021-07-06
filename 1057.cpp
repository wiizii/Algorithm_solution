#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int main() {
    cin >> n >> a >> b;
    int round = 1;
    while (n > 1) {
        if ((a + 1) / 2 == (b + 1) / 2) break;
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        round += 1;
        n /= 2;
    }
    cout << round << "\n";
}