#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> &phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = i + 1; j < phone_book.size(); j++) {
            bool flag = false;
            for (int k = 0; k < phone_book[i].length(); k++) {
                if (phone_book[i][k] != phone_book[j][k]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n;
        vector<string> v;
        for (int i = 0; i < n; i++) {
            cin >> s;
            v.push_back(s);
        }
        if (solution(v))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}