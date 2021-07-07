#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (a.size() < b.size()) swap(a, b);
    for (int i = 0; i < b.size(); i++) a[i] += b[i] - '0';
    for (int i = 0; i < a.size() - 1; i++) {
        int k = a[i] - '0';
        a[i] = (k % 2) + '0';
        a[i + 1] += (k / 2);
    }
    if (a.back() == '2') {
        a.back() = '0';
        a.push_back('1');
    } else if (a.back() == '3') {
        a.back() = '1';
        a.push_back('1');
    }
    while (!a.empty() && a.back() == '0') {
        a.pop_back();
    }
    if (a.empty()) a.push_back('0');
    reverse(a.begin(), a.end());
    cout << a << "\n";
}