#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        bool chk[26];
        memset(chk, 0, sizeof(chk));

        cin >> a >> b;
        for (int i = 0; i < a.size(); i++) chk[a[i] - 'a'] = true;
        bool flag = true;
        if ()
            for (int i = 0; i < b.size(); i++) {
                if (!chk[b[i] - 'a']) {
                    flag = false;
                    break;
                }
            }
        if (flag)
            cout << a << " & " << b << " are anagrams.\n";
        else
            cout << a << " & " << b << " are NOT anagrams.\n";
    }
}