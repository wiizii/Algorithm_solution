#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isCorrect(string str) {
    vector<char> v;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '[')
            v.push_back(str[i]);
        else if (!v.empty() && v.back() == '(' && str[i] == ')')
            v.pop_back();
        else if (!v.empty() && v.back() == '[' && str[i] == ']')
            v.pop_back();
        else if(v.empty() && (str[i] == ']' || str[i] == ')'))
            return false;
    }
    if (v.empty())
        return true;
    else
        return false;
}

int main() {
    string str;
    cin >> str;
    if (!isCorrect(str)) {
        cout << 0 << "\n";
        return 0;
    }
    vector<int> ans;
    vector<char> v;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '[')
            v.push_back(str[i]);
        else if (!v.empty() && v.back() == '(' && str[i] == ')') {
            v.pop_back();
            v.push_back('A');
            ans.push_back(2);
        } else if (!v.empty() && v.back() == '[' && str[i] == ']') {
            v.pop_back();
            v.push_back('A');
            ans.push_back(3);
        } else if (!v.empty() && v.back() == 'A' && str[i] == ')') {
            int tmp = 0;
            while (v.back() == 'A') {
                tmp += ans.back();
                ans.pop_back();
                v.pop_back();
            }
            v.pop_back();
            ans.push_back(tmp * 2);
            v.push_back('A');
        } else if (!v.empty() && v.back() == 'A' && str[i] == ']') {
            int tmp = 0;
            while (v.back() == 'A') {
                tmp += ans.back();
                ans.pop_back();
                v.pop_back();
            }
            v.pop_back();
            ans.push_back(tmp * 3);
            v.push_back('A');
        }
    }

    int ret = 0;
    for (int i = 0; i < ans.size(); i++) ret += ans[i];
    cout << ret << "\n";

    return 0;
}