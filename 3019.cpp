#include <bits/stdc++.h>
using namespace std;

int arr[101];

int main() {
    int c, p;
    int ans = 0;
    cin >> c >> p;
    for (int i = 0; i < c; i++) cin >> arr[i];
    if (p == 1) {
        ans += c;
        for (int i = 0; i <= c - 4; i++)
            if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2] &&
                arr[i] == arr[i + 3])
                ans++;
    } else if (p == 2) {
        for (int i = 0; i <= c - 2; i++)
            if (arr[i] == arr[i + 1]) ans++;
    } else if (p == 3) {
        for (int i = 0; i <= c - 3; i++)
            if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2] - 1) ans++;
        for (int i = 0; i <= c - 2; i++)
            if (arr[i] - 1 == arr[i + 1]) ans++;
    } else if (p == 4) {
        for (int i = 0; i <= c - 3; i++)
            if (arr[i] - 1 == arr[i + 1] && arr[i] - 1 == arr[i + 2]) ans++;
        for (int i = 0; i <= c - 2; i++)
            if (arr[i] == arr[i + 1] - 1) ans++;
    } else if (p == 5) {
        for (int i = 0; i <= c - 3; i++)
            if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2]) ans++;
        for (int i = 0; i <= c - 3; i++)
            if (arr[i] == arr[i + 1] + 1 && arr[i] == arr[i + 2]) ans++;
        for (int i = 0; i <= c - 2; i++)
            if (arr[i] == arr[i + 1] - 1) ans++;
        for (int i = 0; i <= c - 2; i++)
            if (arr[i] - 1 == arr[i + 1]) ans++;
    } else if (p == 6) {
        for (int i = 0; i <= c - 3; i++)
            if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2]) ans++;
        for (int i = 0; i <= c - 3; i++)
            if (arr[i] + 1 == arr[i + 1] && arr[i] + 1 == arr[i + 2]) ans++;
        for (int i = 0; i <= c - 2; i++)
            if (arr[i] == arr[i + 1]) ans++;
        for (int i = 0; i <= c - 2; i++)
            if (arr[i] - 2 == arr[i + 1]) ans++;
    } else if (p == 7) {
        for (int i = 0; i <= c - 3; i++)
            if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2]) ans++;
        for (int i = 0; i <= c - 3; i++)
            if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2] + 1) ans++;
        for (int i = 0; i <= c - 2; i++)
            if (arr[i] == arr[i + 1]) ans++;
        for (int i = 0; i <= c - 2; i++)
            if (arr[i] == arr[i + 1] - 2) ans++;
    }
    cout << ans << "\n";
}