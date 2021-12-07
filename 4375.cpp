#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        ll a = 1, b = 1;
        while (1) {
            if (a % n == 0) break;
            a = (a * 10) % n + 1;
            b++;
        }
        cout << b << "\n";
    }
}