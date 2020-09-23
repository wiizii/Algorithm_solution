#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

set<string> s1, s2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        s1.insert(s);
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        s2.insert(s);
    }
    vector<string> v;
    for (auto iter = s1.begin(); iter != s1.end(); iter++) {
        if (s2.count(*iter)) {
            v.push_back(*iter);
        }
    }
    cout << v.size() << "\n";
    for (string s : v) {
        cout << s << '\n';
    }
    return 0;
}