#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int arr[2] = {1, 0};
    bool t = false;
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] != s[i]) {
            t = !t;
            arr[t]++;
        }
    }
    cout << min(arr[0], arr[1]) << "\n";
}