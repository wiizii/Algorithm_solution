#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v, idx;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        idx.push_back(x);
    }
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());
    for (auto& i : v) {
        auto pos = lower_bound(idx.begin(), idx.end(), i) - idx.begin();
        cout << pos << ' ';
    }
}