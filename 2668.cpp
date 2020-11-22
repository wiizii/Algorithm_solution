#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> v(101, 0);
set<int> s;
int n;

vector<int> find_pair(int s) {
    vector<int> tmp;
    bool flag = false;
    tmp.push_back(s);
    int next = v[s];
    for (int i = 1; i <= n; i++) {
        tmp.push_back(next);
        if (s == next) {
            flag = true;
            break;
        }
        next = v[next];
    }
    if (flag)
        return tmp;
    else {
        tmp.clear();
        return tmp;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++) {
        vector<int> tmp = find_pair(i);
        if (!tmp.empty())
            for (auto &k : tmp) s.insert(k);
    }

    cout << s.size() << "\n";
    for (auto iter = s.begin(); iter != s.end(); iter++) cout << *iter << "\n";

    return 0;
}
