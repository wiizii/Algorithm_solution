#include <iostream>

using namespace std;

int solution(int n, int a, int b) {
    int ans = 0;
    while (a != b) {
        ans++;
        a = (a + 1) >> 1;
        b = (b + 1) >> 1;
    }
    return ans;
}