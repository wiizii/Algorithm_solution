#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    string ans = "";
    cin >> s;
    if (s.size() % 3 == 1)
        s = "00" + s;
    else if (s.size() % 3 == 2)
        s = "0" + s;
    for (int i = 0; i < s.size(); i += 3) {
        string tmp = s.substr(i, 3);
        if (tmp == "000")
            ans += "0";
        else if (tmp == "001")
            ans += "1";
        else if (tmp == "010")
            ans += "2";
        else if (tmp == "011")
            ans += "3";
        else if (tmp == "100")
            ans += "4";
        else if (tmp == "101")
            ans += "5";
        else if (tmp == "110")
            ans += "6";
        else if (tmp == "111")
            ans += "7";
    }
    cout << ans << "\n";
}