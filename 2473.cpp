#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 5001;

int n;
ll arr[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    ll maxValue = INF;
    ll answer[3];

    for (int i = 0; i < n - 2; i++) {
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            ll sum = arr[i] + arr[l] + arr[r];
            if (abs(maxValue) > abs(sum)) {
                maxValue = sum;
                answer[0] = arr[i];
                answer[1] = arr[l];
                answer[2] = arr[r];
            }
            if (sum >= 0)
                r--;
            else
                l++;
        }
    }
    for (int i = 0; i < 3; i++) cout << answer[i] << " ";
}