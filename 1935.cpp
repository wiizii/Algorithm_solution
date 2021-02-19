#include <cstdio>
#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;

map<char, double> m;
stack<double> st;

int main() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        double k;
        cin >> k;
        m[i + 'A'] = k;
    }
    for (int i = 0; i < s.size(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            st.push(m[s[i]]);
        } else {
            double b = st.top();
            st.pop();
            double a = st.top();
            st.pop();
            if (s[i] == '*') st.push(a * b);
            if (s[i] == '/') st.push(a / b);
            if (s[i] == '+') st.push(a + b);
            if (s[i] == '-') st.push(a - b);
        }
    }
    printf("%.2lf", st.top());
}