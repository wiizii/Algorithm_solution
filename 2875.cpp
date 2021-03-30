#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    while (k--) m * 2 <= n ? n-- : m--;
    if (m * 2 <= n)
        cout << m;
    else
        cout << n / 2;
}