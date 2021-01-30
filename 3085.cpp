#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int arr[51][51];
int n;

void getMaxAns(int &ans) {
    for (int i = 0; i < n; i++) {
        int check[4] = {0, 0, 0, 0};
        for (int j = 0; j < n; j++) check[arr[i][j]]++;
        for (int j = 0; j < 4; j++) ans = max(ans, check[j]);
    }
    for (int j = 0; j < n; j++) {
        int check[4] = {0, 0, 0, 0};
        for (int i = 0; i < n; i++) check[arr[i][j]]++;
        for (int i = 0; i < 4; i++) ans = max(ans, check[i]);
    }
}

int main() {
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'C')
                arr[i][j] = 0;
            else if (s[j] == 'P')
                arr[i][j] = 1;
            else if (s[j] == 'Z')
                arr[i][j] = 2;
            else if (s[j] == 'Y')
                arr[i][j] = 3;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            swap(arr[i][j], arr[i][j + 1]);
            getMaxAns(ans);
            swap(arr[i][j], arr[i][j + 1]);
            swap(arr[j][i], arr[j + 1][i]);
            getMaxAns(ans);
            swap(arr[j][i], arr[j + 1][i]);
        }
    }
    cout << ans << "\n";
}