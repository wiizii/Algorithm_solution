#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s, ans;
    stack<char> st;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z')
            ans.push_back(s[i]);
        else {
            if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == '*' || s[i] == '/') {
                while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            } else if (s[i] == '+' || s[i] == '-') {
                while (!st.empty() && st.top() != '(') {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            } else if (s[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
        }
    }
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    cout << ans << "\n";
}