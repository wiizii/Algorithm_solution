#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000001;

bool isPrime[MAX];

void Eratos(int n) {
    if (n <= 1) return;
    for (int i = 1; i <= n; i++) isPrime[i] = true;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i) isPrime[j] = false;
    }
}

int main() {
    int ans = -1;
    int n;
    cin >> n;
    Eratos(n);
}
