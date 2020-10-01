#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    stack<char> s;
    stack<int> a;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '[') {
            s.push(str[i]);
        } else {
            if (!s.empty()) {
                if (str[i] == ')' && s.top() == '(') {
                    s.pop();
                    s.push('a');
                    a.push(2);
                } else if (str[i] == ']' && s.top() == '[') {
                    s.pop();
                    s.push('a');
                    a.push(3);
                } else if (str[i] == ')' && s.top() == 'a') {
                    int x = 0;
                    while (s.top() == 'a') {
                        s.pop();
                        x += a.top();
                        a.pop();
                    }
                    s.pop();
                    a.push(x * 2);
                    s.push('a');
                } else if (str[i] == ']' && s.top() == 'a') {
                    int x = 0;
                    while (s.top() == 'a') {
                        s.pop();
                        x += a.top();
                        a.pop();
                    }
                    s.pop();
                    a.push(x * 3);
                    s.push('a');
                }
            }
        }
    }
    int ans = 0;
    while (!s.empty()) {
        if (s.top() == 'a') {
            ans += a.top();
            a.pop();
            s.pop();
        } else {
            ans = 0;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}