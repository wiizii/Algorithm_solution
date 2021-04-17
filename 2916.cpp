#include <bits/stdc++.h>
using namespace std;

vector<int> angle;
bool check[400];
int n, k;

void solve(int acc, int cnt) {
    if (cnt == n) {
        while (acc >= 360) acc -= 360;
        while (acc < 0) acc += 360;
        int tmp = acc;
        while (tmp < 360) {
            check[tmp] = true;
            check[360 - tmp] = true;
            if (tmp == 0) break;
            tmp += acc;
        }
        return;
    }
    solve(acc + angle[cnt], cnt + 1);
    solve(acc - angle[cnt], cnt + 1);
    solve(acc, cnt + 1);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        angle.push_back(x);
        check[x] = true;
    }

    solve(0, 0);

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        if (check[x])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}