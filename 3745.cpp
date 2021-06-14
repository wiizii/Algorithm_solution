#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
    int N, x;
    while (scanf("%d", &N) > EOF) {
        v.clear();
        for (int i = 0; i < N; i++) {
            cin >> x;
            if (v.empty() || v.back() < x) {
                v.push_back(x);
            } else {
                auto iter = lower_bound(v.begin(), v.end(), x);
                *iter = x;
            }
        }
        cout << v.size() << "\n";
    }
    return 0;
}