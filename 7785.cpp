#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

set<string> s;

bool cmp(const string &a, const string &b) { return a > b; }

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (b == "enter") {
            s.insert(a);
        } else {
            s.erase(a);
        }
    }
    vector<string> v;
    for (auto it = s.begin(); it != s.end(); it++) {
        v.push_back(*it);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
}