#include <bits/stdc++.h>
using namespace std;

vector<int> angle;
bool check[400];
int n, k;

void solve(int acc, int cnt) {}

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