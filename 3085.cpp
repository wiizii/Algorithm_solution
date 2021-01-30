#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

char arr[51][51];
int n;

int getAns() {
    int ret = 1;
    for (int i = 0; i < n; i++) {
        int tmp = 1;
        for (int j = 0; j < n - 1; j++) {
            if (arr[i][j] == arr[i][j + 1]) {
                tmp++;
                ret = max(ret, tmp);
            } else
                tmp = 1;
        }
    }
    for (int j = 0; j < n; j++) {
        int tmp = 1;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i][j] == arr[i + 1][j]) {
                tmp++;
                ret = max(ret, tmp);
            } else
                tmp = 1;
        }
    }
    return ret;
}

int main() {
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) arr[i][j] = s[j];
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            swap(arr[i][j], arr[i][j + 1]);
            ans = max(getAns(), ans);
            swap(arr[i][j], arr[i][j + 1]);
            swap(arr[j][i], arr[j + 1][i]);
            ans = max(getAns(), ans);
            swap(arr[j][i], arr[j + 1][i]);
        }
    }
    cout << ans << "\n";
}