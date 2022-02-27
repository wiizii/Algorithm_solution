#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

vector<int> v;
int candidate[MAX];

int findLeastCandidateValue(const vector<int> &a) {
    int minValue = 0x3f3f3f3f;
    int ret = 0;
    for (int i = 0; i < a.size(); i++) {
        if (minValue > candidate[a[i]]) {
            minValue = candidate[a[i]];
            ret = a[i];
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        auto iter = find(v.begin(), v.end(), x);
        if (iter == v.end()) {
            if (v.size() == n) {
                int leastCandidateValue = findLeastCandidateValue(v);
                auto iter2 = find(v.begin(), v.end(), leastCandidateValue);
                candidate[*iter2] = 0;
                v.erase(iter2);
                v.push_back(x);
                candidate[x]++;
            } else {
                v.push_back(x);
                candidate[x]++;
            }
        } else {
            candidate[*iter]++;
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}