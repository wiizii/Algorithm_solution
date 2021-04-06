#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, v[i].second - i);
    }
    cout << ans + 1 << "\n";
}