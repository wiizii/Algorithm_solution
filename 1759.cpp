#include <algorithm>
#include <iostream>
using namespace std;

int l, c;
char arr[20];
char buf[20];

bool isCorrect() {
    int a = 0, b = 0;
    for (int i = 0; i < l; i++) {
        if (buf[i] == 'a' || buf[i] == 'e' || buf[i] == 'i' || buf[i] == 'o' ||
            buf[i] == 'u')
            a++;
        else
            b++;
    }
    if (a >= 1 && b >= 2)
        return true;
    else
        return false;
}

void solve(int cnt, int start) {
    if (cnt == l) {
        if (isCorrect()) {
            for (int i = 0; i < l; i++) cout << buf[i];
            cout << "\n";
        }
        return;
    }

    for (int i = start; i < c; i++) {
        buf[cnt] = arr[i];
        solve(cnt + 1, i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> c;
    for (int i = 0; i < c; i++) cin >> arr[i];
    sort(arr, arr + c);
    solve(0, 0);
    return 0;
}