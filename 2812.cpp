#include <bits/stdc++.h>
using namespace std;

deque<char> dq;
string s;
int n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> s;

    for (int i = 0; i < n; i++) {
        while (k && !dq.empty() && dq.back() < s[i]) {
            dq.pop_back();
            k--;
        }
        dq.push_back(s[i]);
    }
    for (int i = 0; i < dq.size() - k; i++) cout << dq[i];
}