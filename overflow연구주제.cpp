#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool a[10000000];
string s;
string ans;
int cnt = 0;

void set_primenum(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (a[i] == false) {
            for (int j = i + i; j <= n; j += i) {
                a[j] = true;
            }
        }
    }
}
void foo(int x) {
    cout << "sex" << '\n';
    if (ans != "" && a[stoi(ans)] == 0) {
        cout << ans << '\n';
        cnt++;
        return;
    }
    cout << "????: " << ',' << s << '\n';
    for (int i = x; i < s.size(); i++) {
        ans += s[i];
        cout << ans << '\n';
        foo(x + 1);
        ans.pop_back();
    }
}
int solution(string numbers) {
    s = numbers;
    cout << s << '\n';
    cout << numbers << '\n';
    cout << s.size() << '\n';
    set_primenum(10000000);
    foo(0);
    return cnt;
}

///////////////

int main() { solution("17"); }