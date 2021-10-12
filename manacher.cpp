#include <bits/stdc++.h>
using namespace std;

int A[10000];

void manachers(string s) {
    int r = 0, p = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (i <= r)
            A[i] = min(A[2 * p - i], r - i);
        else
            A[i] = 0;
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < n &&
               s[i - A[i] - 1] == s[i + A[i] + 1])
            A[i]++;
        if (r < i + A[i]) {
            r = i + A[i];
            p = i;
        }
    }
}