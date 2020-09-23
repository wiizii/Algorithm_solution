#include <algorithm>
#include <iostream>
using namespace std;
bool broken[10];

int abs(int a) { return a >= 0 ? a : -a; }
int length(int a) {
    int d = 10;
    int i = 1;
    while(1){
        if(a < d)
            return i;
        d*=10; i++;
    }
}

bool CanPressButton(int n) {
    if (n == 0 && broken[0]) {
        return false;
    }
    while (0 < n) {
        if (broken[n % 10]) return false;
        n /= 10;
    }
    return true;
}

int main() {
    int to, from = 100, m, ans = 0x3f3f3f3f;
    cin >> to >> m;
    while (m--) {
        int k;
        cin >> k;
        broken[k] = true;
    }
    for (int i = 0; i <= 1000000; i++) {
        if (CanPressButton(i)) {
            ans = min(ans, length(i) + abs(to - i));
        }
    }
    ans = min(ans, abs(to - 100));
    cout << ans << '\n';

    return 0;
}