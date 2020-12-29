#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct student {
    string name;
    int a, b, c;
};

bool cmp(const student &s1, const student &s2) {
    if (s1.a > s2.a)
        return true;
    else if (s1.a == s2.a) {
        if (s1.b < s2.b)
            return true;
        else if (s1.b == s2.b) {
            if (s1.c > s2.c)
                return true;
            else if (s1.c == s2.c) {
                if (s1.name < s2.name)
                    return true;
                else
                    return false;
            } else
                return false;
        } else
            return false;
    } else
        return false;
}

int main() {
    vector<student> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        student s;
        cin >> s.name >> s.a >> s.b >> s.c;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++) cout << v[i].name << "\n";
    return 0;
}
