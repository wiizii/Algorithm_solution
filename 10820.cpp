#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while (1) {
        getline(cin, s);
        if (s.size() == 0) break;
        int a = 0, b = 0, c = 0, d = 0;
        for (auto i : s) {
            if (islower(i)) a++;
            if (isupper(i)) b++;
            if (isdigit(i)) c++;
            if (i == ' ') d++;
        }
        cout << a << " " << b << " " << c << " " << d << "\n";
    }
}