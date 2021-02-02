#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define ll long long
using namespace std;

bool cmp(const string &a, const string &b) {
    if (a.size() < b.size()) {
        return true;
    } else if (a.size() == b.size()) {
        return a < b;
    } else
        return false;
}

int main() {
    ll s, t;
    cin >> s >> t;
    vector<string> ans;
    if (s == t) {
        cout << 0 << "\n";
        return 0;
    }
    queue<pair<ll, string>> q;
    q.push({s, ""});
    q.push({1, "/"});
    q.push({0, "-"});
    while (!q.empty()) {
        ll cur = q.front().first;
        string s = q.front().second;
        q.pop();
        if (cur == t) ans.push_back(s);
        if (cur != 0 && cur != 1 && cur * cur <= t)
            q.push({cur * cur, s + "*"});
        if (cur != 0 && cur + cur <= t) q.push({cur + cur, s + "+"});
    }
    if (ans.empty())
        cout << "-1";
    else {
        sort(ans.begin(), ans.end(), cmp);
        cout << ans[0] << "\n";
    }
}