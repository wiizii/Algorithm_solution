#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    int x = -1, idx = -1;

    for (int i = l; i <= 100; i++) {
        int t = (i - 1) * i / 2;
        if ((n - t) % i == 0 && (n - t) / i >= 0) {
            x = (n - t) / i;
            idx = i;
            break;
        }
    }

    if (x == -1) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < idx; i++) cout << x + i << " ";
    }
}