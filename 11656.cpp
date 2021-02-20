#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) v.push_back(s.substr(i));
    sort(v.begin(), v.end());
    for (auto &i : v) cout << i << "\n";
}