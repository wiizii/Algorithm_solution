#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int check[101];

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(check, 0, sizeof(check));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            check[a]++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) ans = max(ans, check[i]);
        cout << ans << "\n";
    }
}