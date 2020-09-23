#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, string> m1;
map<string, string> m2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string monster;
        cin >> monster;
        m1.insert({monster, to_string(i)});
        m2.insert({to_string(i), monster});
    }
    while (m--) {
        string t;
        cin >> t;
        if (m1.count(t))
            cout << m1[t] << '\n';
        else
            cout << m2[t] << '\n';
    }
}
