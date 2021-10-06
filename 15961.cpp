#include <bits/stdc++.h>
using namespace std;

const int MAX = 3000001;

int n, d, k, c;
int arr[MAX];
int check[3001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0, r = k;
    int cnt = 0;
    for (int i = l; i < r; i++) {
        if (!check[arr[i]]) {
            cnt++;
        }
        check[arr[i]]++;
    }

    int answer = cnt;

    while (l < n) {
        check[arr[l]]--;
        if (!check[arr[l]]) {
            cnt -= 1;
        }
        l++;
        r = r % n;
        if (!check[arr[r]]) {
            cnt += 1;
        }
        check[arr[r]]++;
        r++;
        if (check[c])
            answer = max(answer, cnt);
        else
            answer = max(answer, cnt + 1);
    }
    cout << answer << "\n";
}