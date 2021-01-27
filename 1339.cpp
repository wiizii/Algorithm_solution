#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int arr[27];

bool cmp(const int &a, const int &b) { return a > b; }

int main() {
    string s;
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int cnt = 1;
        for (int j = s.size() - 1; j >= 0; j--) {
            arr[s[j] - 'A'] += cnt;
            cnt *= 10;
        }
    }
    vector<int> v;
    for (int i = 0; i < 27; i++) {
        if (arr[i]) v.push_back(arr[i]);
    }
    sort(v.begin(), v.end(), cmp);
    int k = 9;
    for (int i = 0; i < v.size(); i++) {
        ans += v[i] * k;
        k--;
    }
    cout << ans << "\n";
}