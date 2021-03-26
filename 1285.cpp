#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int n;

bool init_m[21][21];
bool m[21][21];

void rev(int isrow, int k) {
    if (isrow) {
        for (int i = 0; i < n; i++) m[k][i] = !m[k][i];
    } else {
        for (int i = 0; i < n; i++) m[i][k] = !m[i][k];
    }
}

void init() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) m[i][j] = init_m[i][j];
}

int main() {
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            init_m[i][j] = s[j] == 'H' ? true : false;
            if (init_m[i][j]) ans++;
        }
    }
    int set = (1 << n) - 1;
    for (int subset = set;; subset = ((subset - 1) & set)) {
        init();
        int cmp = 0;
        for (int i = 0; i < n; i++) {
            int cur = 1 << i;
            if ((subset & cur) == cur) rev(0, i);
        }
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (!m[i][j]) cnt++;
            }
            if (cnt > n - cnt) {
                rev(1, i);
                cmp += n - cnt;
            } else {
                cmp += cnt;
            }
        }
        ans = min(ans, cmp);
        if (subset == 0) break;
    }

    cout << ans << "\n";
}