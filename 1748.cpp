#include <iostream>
using namespace std;

int getDigits(int n) {
    int ret = 0;
    while (n > 0) {
        n /= 10;
        ret++;
    }
    return ret;
}

int main() {
    int n;
    int ans = 0;
    cin >> n;
    long long cnt[10] = {0,      9,       180,      2700,      36000,
                         450000, 5400000, 63000000, 720000000, 9};
    int k = getDigits(n);
    for (int i = 1; i < k; i++) ans += cnt[i];
    int d = 1;
    for (int i = 0; i < k - 1; i++) d *= 10;
    ans += (n - d + 1) * k;
    cout << ans << endl;
    return 0;
}