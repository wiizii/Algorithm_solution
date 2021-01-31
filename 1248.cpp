#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int arr[11];
char oper[11][11];
int n;

bool isPossible(int cnt) {
    for (int i = 0; i < cnt; i++) {
        int sum = 0;
        for (int j = i; j < cnt; j++) {
            sum += arr[j];
            if (oper[i][j] == '-' && sum >= 0) return false;
            if (oper[i][j] == '0' && sum != 0) return false;
            if (oper[i][j] == '+' && sum <= 0) return false;
        }
    }
    return true;
}

void solve(int cnt) {
    if (cnt == n) {
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        exit(0);
    }
    for (int i = -10; i <= 10; i++) {
        arr[cnt] = i;
        if (isPossible(cnt + 1)) solve(cnt + 1);
    }
}

int main() {
    int idx = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) oper[i][j] = s[idx++];
    solve(0);
    return 0;
}