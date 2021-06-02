#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m;
ll arr[11];
ll answer = 0;
vector<ll> sel;

void combi(int start) {
    if (!sel.empty()) {
        ll tmp = 1;
        for (auto i : sel) tmp *= i;
        if (sel.size() % 2)
            answer += m / tmp;
        else
            answer -= m / tmp;
    }
    for (int i = start; i < n; i++) {
        sel.push_back(arr[i]);
        combi(i + 1);
        sel.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    combi(0);
    cout << answer << "\n";
}