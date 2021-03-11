#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<pair<char, int>> st;

int main() {
    string s, b;
    cin >> s >> b;

    int cnt = 0;
    for (char &c : s) {
        if (c == b[cnt]) {
            cnt++;
            st.push({c, cnt});
        } else {
            cnt = 0;
            if (c == b[cnt]) cnt++;
            st.push({c, cnt});
        }
        if (cnt == b.size())
            while (cnt--) st.pop();
        if (!st.empty()) cnt = st.top().second;
    }
    string ans = "";
    while (!st.empty()) {
        ans.push_back(st.top().first);
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    if (ans.empty())
        cout << "FRULA\n";
    else
        cout << ans << "\n";
}