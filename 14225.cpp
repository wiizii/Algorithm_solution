#include <iostream>
using namespace std;

int n;
int arr[21];
bool check[2000001];

void solve(int cnt, int sum) {
    check[sum] = true;
    if (cnt == n) return;
    solve(cnt + 1, sum + arr[cnt]);
    solve(cnt + 1, sum);
}

int main() {
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    solve(0, 0);
    for (int i = 1; i <= 2000000; i++)
        if (!check[i]) {
            ans = i;
            break;
        }
    cout << ans << "\n";
}