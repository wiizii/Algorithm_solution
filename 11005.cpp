#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n, b;
    stack<int> s;
    cin >> n >> b;
    while (n > 0) {
        s.push(n % b);
        n /= b;
    }
    string ans = "";
    while (!s.empty()) {
        int t = s.top();
        s.pop();
        if (t < 10)
            ans += ('0' + t);
        else
            ans += ('A' + t - 10);
    }
    cout << ans << "\n";
}