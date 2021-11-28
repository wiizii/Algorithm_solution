#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int q = 0, w = 0;
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] > sizes[i][1]) swap(sizes[i][0], sizes[i][1]);
        q = max(q, sizes[i][0]);
        w = max(w, sizes[i][1]);
    }
    return q * w;
}