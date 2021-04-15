#include <bits/stdc++.h>
using namespace std;

vector<string> v;

bool cmp(const string &a, const string &b) { return a + b > b + a; }

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    string ans = "";
    for (int i = 0; i < v.size(); i++) ans += v[i];
    if (ans.front() == '0') {
        int tmp = 0;
        while (ans[tmp] == '0') {
            tmp++;
        }
        ans = ans.substr(tmp);
    }
    if (ans == "") ans = "0";
    cout << ans << "\n";
}