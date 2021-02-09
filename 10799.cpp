#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<char> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            v.push_back(s[i]);
        else if (!v.empty() && v.back() == '(' && s[i] == ')') {
            v.pop_back();
            v.push_back('L');
        } else if (!v.empty() && v.back() == 'L' && s[i] == ')')
            v.push_back(s[i]);
        else
            v.push_back(s[i]);
    }
    int ans = 0;
    vector<int> st;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == '(') {
            st.push_back(0);
        } else if (v[i] == ')') {
            int tmp = st.back();
            ans += st.back() + 1;
            st.pop_back();
            if (!st.empty()) st.back() += tmp;

        } else if (!st.empty() && v[i] == 'L')
            st.back() += 1;
    }
    cout << ans << "\n";
}