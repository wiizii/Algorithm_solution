#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> st;

int solution(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (st.empty() || st.top() != s[i])
            st.push(s[i]);
        else
            st.pop();
    }
    return st.empty() ? 1 : 0;
}