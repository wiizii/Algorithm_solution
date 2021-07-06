#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;

bool cmp(const string &a, const string &b) {
    if (a.size() < b.size())
        return true;
    else if (a.size() == b.size()) {
        int cnt_a = 0, cnt_b = 0;
        for (int i = 0; i < a.size(); i++)
            if (isdigit(a[i])) cnt_a += a[i] - '0';
        for (int i = 0; i < b.size(); i++)
            if (isdigit(b[i])) cnt_b += b[i] - '0';
        if (cnt_a < cnt_b)
            return true;
        else if (cnt_a == cnt_b)
            return a < b;
        else
            return false;
    } else
        return false;
}

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), cmp);
    for (auto &i : v) cout << i << "\n";
}