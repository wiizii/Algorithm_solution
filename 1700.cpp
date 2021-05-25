#include <bits/stdc++.h>
using namespace std;

int arr[101];
set<int> plug;

int main() {
    int answer = 0;
    int n, k;
    int idx = 0;
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> arr[i];
    for (int i = 0; i < k; i++) {
        if (plug.count(arr[i])) continue;
        if (plug.size() == n) {
            int last = 0, e = 0;
            for (auto& p : plug) {
                bool flag = false;
                for (int j = i + 1; j < k; j++) {
                    if (p == arr[j]) {
                        flag = true;
                        last = max(last, j);
                        break;
                    }
                }
                if (!flag) e = p;
            }
            if (e)
                plug.erase(e);
            else
                plug.erase(arr[last]);
            plug.insert(arr[i]);
            answer++;
        } else {
            plug.insert(arr[i]);
        }
    }
    cout << answer << "\n";
}