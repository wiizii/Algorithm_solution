#include <iostream>
#include <string>
using namespace std;

int arr[10001];
int rem = (1 << 26) - 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int bit = 0;
        for (char &c : s) {
            bit |= 1 << (c - 'a');
        }
        arr[i] = bit;
    }
    while (m--) {
        int cnt = 0;
        int o;
        char x;
        cin >> o >> x;
        if (o == 1)
            rem ^= 1 << (x - 'a');
        else
            rem |= 1 << (x - 'a');
        for (int i = 0; i < n; i++)
            if ((arr[i] & rem) == arr[i]) cnt++;
        cout << cnt << "\n";
    }
}