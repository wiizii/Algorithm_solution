#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    string ans;
    getline(cin, s);
    bool flag = false;
    string tmp = "";
    for (char &c : s) {
        if (c == '<') {
            reverse(tmp.begin(), tmp.end());
            ans += tmp;
            tmp = "";
            flag = true;
            ans.push_back(c);
            continue;
        }
        if (c == '>') {
            flag = false;
            ans.push_back(c);
            continue;
        }
        if (!flag && c == ' ') {
            reverse(tmp.begin(), tmp.end());
            ans += tmp + " ";
            tmp = "";
            continue;
        }
        if (flag) {
            ans.push_back(c);
        } else {
            tmp.push_back(c);
        }
    }
    reverse(tmp.begin(), tmp.end());
    ans += tmp;
    cout << ans << "\n";
}