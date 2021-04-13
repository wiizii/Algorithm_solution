#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int a = 0, b = 0, c = 0;
    cin >> t;
    a = t / 300;
    t = t % 300;
    b = t / 60;
    t = t % 60;
    c = t / 10;
    t = t % 10;
    if (t != 0)
        cout << "-1\n";
    else
        cout << a << " " << b << " " << c << "\n";
}