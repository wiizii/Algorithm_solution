#include <iostream>
#include <vector>
using namespace std;

const int MAX = 4000000;
bool isPrime[MAX + 1];
vector<int> prime;

void setPrime(int n) {
    for (int i = 2; i <= n; i++) isPrime[i] = true;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) prime.push_back(i);
    }
}
int main() {
    int n;
    cin >> n;
    setPrime(n);
    int ans = 0;
    int l = 0, r = 0, sum = 0;
    while (1) {
        if (sum >= n) {
            sum -= prime[l++];
        } else if (r == prime.size()) {
            break;
        } else {
            sum += prime[r++];
        }
        if (sum == n) ans++;
    }
    cout << ans << "\n";
}