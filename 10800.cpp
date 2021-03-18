#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int acc_color[200001];
int acc[200001];

struct info {
    int num, color, size;
};

vector<info> v;

bool cmp(const info &a, const info &b) { return a.size < b.size; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int c, s;
        cin >> c >> s;
        v.push_back({i, c, s});
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        acc[v[i + 1].num] = acc[v[i].num] + v[i].size;
        int j = i - 1;
        while (v[i].size == v[j].size) {
            if (v[i].color != v[j].color) acc[v[i].num] -= v[i].size;
            j--;
        }
        acc[v[i].num] -= acc_color[v[i].color];
        acc_color[v[i].color] += v[i].size;
    }

    for (int i = 1; i <= n; i++) {
        cout << acc[i] << "\n";
    }
}