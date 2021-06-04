#include <bits/stdc++.h>
using namespace std;

// MAX값 2배로 했어야 했음..
const int MAX = 200000 + 1;

int parent[MAX];
int setSize[MAX];

int Find(int x) {
    if (x == parent[x])
        return x;
    else
        return parent[x] = Find(parent[x]);
}

void Merge(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y) {
        if (setSize[x] < setSize[y]) swap(x, y);
        parent[y] = x;
        setSize[x] += setSize[y];
        setSize[y] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        map<string, int> name;
        int n;
        cin >> n;

        for (int i = 0; i < MAX; i++) {
            parent[i] = i;
            setSize[i] = 1;
        }

        int idx = 1;
        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (name.count(s1) == 0) name[s1] = idx++;
            if (name.count(s2) == 0) name[s2] = idx++;

            int p_s1 = Find(name[s1]);
            int p_s2 = Find(name[s2]);

            if (p_s1 == p_s2)
                cout << max(setSize[p_s1], setSize[p_s2]) << "\n";
            else {
                Merge(p_s1, p_s2);
                cout << max(setSize[p_s1], setSize[p_s2]) << "\n";
            }
        }
    }
}
