#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, w, h, x;
    cin >> n >> w >> h;
    int diagonalSquare = w * w + h * h;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x <= w || x <= h || x * x <= diagonalSquare) {
            cout << "DA\n";
        } else {
            cout << "NE\n";
        }
    }
}