#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int stob(string s) {
    int ret = 0;
    reverse(s.begin(), s.end());
    for (int i = 0, k = 1; i < s.size(); i++, k *= 2)
        if (s[i] == '1') ret += k;
    return ret;
}

string btos(int b, int n) {
    string tmp = "";
    for (int i = 0, k = 1; i < n; i++, k <<= 1) {
        if (b & k)
            tmp += "1";
        else
            tmp += "0";
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k = (1 << n) - 1;
    int a = stob(s);
    for (int i = 0; i < pow(2, n) / 2; i++) {
        cout << btos(a, n) << "\n";
        cout << btos(a ^ k, n) << "\n";
        a++;
        if (a > k) a = 1;
    }
}