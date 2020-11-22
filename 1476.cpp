#include <iostream>
using namespace std;

int main() {
    int e, s, m;
    cin >> e >> s >> m;
    int a = 1, b = 1, c = 1;
    int t = 1;
    while (1) {
        if (e == a && s == b && m == c) break;
        a = a % 15 + 1;
        b = b % 28 + 1;
        c = c % 19 + 1;
        t++;
    }
    cout << t << "\n";
    return 0;
}