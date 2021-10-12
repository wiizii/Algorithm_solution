#include <bits/stdc++.h>
using namespace std;

const int MAX = 2000000;
bool isPrime[MAX + 1];
int n;

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

bool isPalindrome(int n) {
    string s = to_string(n);
    int size = s.size();
    for (int i = 0; i < size / 2; i++) {
        if (s[i] != s[size - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    eratos(MAX);
    for (int i = n; true; i++) {
        if (isPrime[i] && isPalindrome(i)) {
            cout << i << "\n";
            return 0;
        }
    }
}