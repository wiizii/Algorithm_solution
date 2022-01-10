#include <bits/stdc++.h>
using namespace std;

vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (N[begin + matched] == N[matched]) {
            ++matched;
            pi[begin + matched - 1] = matched;
        } else {
            if (matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (1) {
        string s;
        cin >> s;
        if (s == "." && s.size() == 1) break;
        vector<int> pi = getPartialMatch(s);
        if (pi.back() == 0 || pi.back() % (s.size() - pi.back()))
            cout << 1 << "\n";
        else
            cout << s.size() / (s.size() - pi.back()) << "\n";
    }
}