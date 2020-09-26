#include <iostream>
#include <set>
using namespace std;

multiset<long long> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        s.clear();
        int k;
        cin >> k;
        while (k--) {
            char c;
            long long n;
            cin >> c >> n;
            if (c == 'I') {
                s.insert(n);
            }
            if (c == 'D') {
                if (!s.empty()) {
                    if (n == 1)
                        s.erase(--s.end());
                    else
                        s.erase(s.begin());
                }
            }
        }
        if (s.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << *(--s.end()) << ' ' << *s.begin() << '\n';
        }
    }
}