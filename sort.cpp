#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
bool check[9];

void solve(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (check[i] == false) {
            v.push_back(i);
            check[i] = true;
            solve(cnt + 1);
            check[i] = false;
            v.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;
    solve(0);
    return 0;
}