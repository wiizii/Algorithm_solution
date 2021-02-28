#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        s.push_back('a');
    }
    cout << s;
}