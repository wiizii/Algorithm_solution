#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    for (int i = 0; i < s.size(); i++) {
        if ('a' <= s[i] && s[i] <= 'z') s[i] -= 32;
        while (s[i] != ' ' && i < s.size()) {
            i++;
            if ('A' <= s[i] && s[i] <= 'Z') s[i] += 32;
        }
    }
    return s;
}