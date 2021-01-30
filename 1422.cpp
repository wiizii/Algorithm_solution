#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string s[1001];

bool cmp(const string &a, const string &b) { return a + b > b + a; }
bool cmp2(const string &a, const string &b) { return stoi(a) > stoi(b); }

int main() {
    string ans = "";
    int k, n;
    cin >> k >> n;
    for (int i = 0; i < k; i++) cin >> s[i];
    sort(s, s + k, cmp2);
    for (int i = k; i < n; i++) {
        s[i] = s[0];
    }
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++) {
        ans += s[i];
    }
    cout << ans << "\n";
}