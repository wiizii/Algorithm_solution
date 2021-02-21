#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (islower(s[i])) {
            int a = (s[i] - 'a' + 13) % 26 + 'a';
            s[i] = a;
        }
        if (isupper(s[i])) {
            s[i] = (s[i] - 'A' + 13) % 26 + 'A';
        }
    }
    cout << s << "\n";
}