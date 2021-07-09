#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0, cnt = 0; j < n; j++) {
            if (arr[j] == 0 && cnt == x) {
                arr[j] = i + 1;
                break;
            }
            if (arr[j] == 0) cnt++;
        }
    }
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}