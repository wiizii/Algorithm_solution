#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int n;
string s[MAX];

bool cmp(const string &a, const string &b) { return a + b > b + a; }
bool cmp2(const string &a, const string &b) {
    if (a.size() > b.size())
        return true;
    else if (a.size() == b.size())
        return a + b > b + a;
    else
        return false;
}

string myreverse(string &a) {
    string tmp = "";
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] == '6')
            tmp += '9';
        else if (a[i] == '9')
            tmp += '6';
        else
            tmp += a[i];
    }
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        s[i] = myreverse(s[i]);
    }
    sort(s, s + n, cmp);
    string ans = "";
    for (int i = 0; i < n; i++) ans += s[i];
    sort(s, s + n, cmp2);
    ans = max(s[0] + ans, ans + s[0]);
    ans = myreverse(ans);
    cout << ans << "\n";
}