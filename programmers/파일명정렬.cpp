#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct file {
    string head;
    int number;
};

struct file parse(const string &s) {
    struct file f = {"", 0};
    string tmp = "";
    int i = 0;
    while (i != s.size()) {
        if ('0' <= s[i] && s[i] <= '9') break;
        if ('A' <= s[i] && s[i] <= 'Z')
            f.head += (s[i] + 32);
        else
            f.head += s[i];
        i++;
    }
    while (i != s.size()) {
        if (!('0' <= s[i] && s[i] <= '9') || tmp.size() == 5) break;
        tmp += s[i];
        i++;
    }
    f.number = stoi(tmp);
    return f;
}

bool cmp(const string &A, const string &B) {
    struct file a = parse(A);
    struct file b = parse(B);
    if (a.head < b.head)
        return true;
    else if (a.head == b.head) {
        if (a.number < b.number)
            return true;
        else
            return false;
    } else
        return false;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), cmp);
    return files;
}