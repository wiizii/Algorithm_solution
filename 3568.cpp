#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;

int main() {
    string s;
    getline(cin, s);
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ' && s[i] != ';')
            tmp += s[i];
        else {
            v.push_back(tmp);
            tmp = "";
        }
    }
    for (int i = 1; i < v.size(); i++) {
        string ans = v[0];
        if (v[i].back() == ',') v[i].pop_back();
        while (!isalpha(v[i].back())) {
            if (v[i].back() == '*')
                ans += '*';
            else if (v[i].back() == '&')
                ans += '&';
            else if (v[i].back() == ']') {
                ans += "[]";
                v[i].pop_back();
            } else
                break;
            v[i].pop_back();
        }
        ans += ' ';
        ans += v[i];
        ans += ';';
        cout << ans << "\n";
    }
}