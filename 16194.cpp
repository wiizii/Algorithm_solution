#include <algorithm>
#include <iostream>
using namespace std;

int p[1001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - j; j++) {
            p[i] = min(p[i], p[j] + p[i - j]);
        }
    }
    cout << p[n] << "\n";
    return 0;
}