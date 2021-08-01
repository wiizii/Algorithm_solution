#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int MAX = 100001;

int arr[MAX];
int n, m;

int getBlueray(int mid) {
    int ret = 0;
    int tmp = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        if (tmp + arr[i] > mid) {
            ret++;
            tmp = arr[i];
        } else
            tmp += arr[i];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int max_num = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        max_num = max(max_num, arr[i]);
    }
    int l = max_num, r = 1000000000, mid;
    int ans = 0x3f3f3f3f;
    while (l <= r) {
        mid = (l + r) / 2;
        int ret = getBlueray(mid);
        if (ret <= m) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
}
