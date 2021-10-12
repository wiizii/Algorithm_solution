#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

bool isPrime[MAX];
void eratos(int n) {
    for (int i = 2; i <= n; i++) isPrime[i] = true;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}