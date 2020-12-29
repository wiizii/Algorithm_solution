#include <iostream>
using namespace std;

int MAX = -0x3f3f3f3f;
int MIN = 0x3f3f3f3f;
int n;
int arr[11];
int oper[4];

void solve(int cnt, int plus, int sub, int mul, int div, int result) {
    if (cnt == n) {
        MAX = max(MAX, result);
        MIN = min(MIN, result);
        return;
    }
    if (cnt == 0) {
        solve(cnt + 1, plus, sub, mul, div, result + arr[cnt]);
        return;
    }
    if (plus != oper[0])
        solve(cnt + 1, plus + 1, sub, mul, div, result + arr[cnt]);
    if (sub != oper[1])
        solve(cnt + 1, plus, sub + 1, mul, div, result - arr[cnt]);
    if (mul != oper[2])
        solve(cnt + 1, plus, sub, mul + 1, div, result * arr[cnt]);
    if (div != oper[3])
        solve(cnt + 1, plus, sub, mul, div + 1, result / arr[cnt]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < 4; i++) cin >> oper[i];
    solve(0, 0, 0, 0, 0, 0);
    cout << MAX << "\n" << MIN << "\n";
    return 0;
}