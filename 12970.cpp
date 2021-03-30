#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a = n / 2;
    int b = n - a;
    if (a * b < k) {
        cout << -1 << "\n";
        return 0;
    }
    string s = "";
    for (int i = 0; i < a; i++) s.push_back('A');
    for (int i = 0; i < b; i++) s.push_back('B');
    int num = a * b;
    while (num != k) {
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == 'A' && s[i + 1] == 'B') {
                swap(s[i], s[i + 1]);
                break;
            }
        }
        num--;
    }
    cout << s << "\n";
}