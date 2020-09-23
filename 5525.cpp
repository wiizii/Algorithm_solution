#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m, ans = 0;
    string s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        if (s[i + 1] == 'O' && s[i + 2] == 'I') {
            int O = 0;
            while (s[i] == 'I' && s[i + 1] == 'O') {
                i += 2;
                O++;
                if (s[i] == 'I' && O == n) {
                    O--;
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
}