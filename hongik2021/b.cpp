#include <bits/stdc++.h>
using namespace std;

string s[5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 5; i++) cin >> s[i];

    for (int i = 0; i < s[0].size(); i++) {
        if (s[0][i] == 'o') {
            s[0][i] = '.';
            s[1][i] = 'o';
            s[2][i] = 'm';
            s[3][i] = 'l';
            s[4][i] = 'n';
        } else if (s[0][i] == '.' && s[1][i] == 'o') {
            s[0][i] = 'o';
            s[1][i] = 'w';
            s[2][i] = 'l';
            s[3][i] = 'n';
            s[4][i] = '.';
        }
    }
    for (int i = 0; i < 5; i++) cout << s[i] << "\n";
}