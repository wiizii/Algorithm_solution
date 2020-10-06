#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string a, b, c;
        bool flag = true;
        int i = 0, j = 0;
        cin >> a >> b >> c;

        for (int k = 0; k < c.size(); k++) {
            if (c[k] == a[i] && c[k] == b[j]) {
                i <= j ? i++ : j++;
            } else if (c[k] == a[i] && c[k] != b[j]) {
                i++;
            } else if (c[k] != a[i] && c[k] == b[j]) {
                j++;
            } else {
                flag = false;
            }
        }

        cout << "Data set " << t << ": ";
        if (flag)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}