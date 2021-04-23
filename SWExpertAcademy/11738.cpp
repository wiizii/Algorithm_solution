#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, d;
int arr[101];
int a[101];

void click(int k) {
    for (int i = max(k - d, 1); i <= min(k + d, n); i++) a[i] = !a[i];
}

int main() {
    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        int ans = INF;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        int _set = (1 << d) - 1;
        for (int subset = _set;; subset = (subset - 1) & _set) {
            int tmp = 0;
            for (int i = 1; i <= n; i++) a[i] = arr[i];
            for (int i = 1, s = 1; i <= d; i++, s <<= 1) {
                if ((subset & s) == s) {
                    click(i);
                    tmp++;
                }
            }
            for (int i = d + 1; i <= n; i++) {
                if (a[i - d]) {
                    tmp++;
                    click(i);
                }
            }
            bool flag = true;
            for (int i = 1; i <= n; i++) {
                if (a[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans = min(ans, tmp);
            if (subset == 0) break;
        }

        cout << "#" << test_case << " ";
        if (ans != INF)
            cout << ans << "\n";
        else
            cout << "impossible\n";
    }
}