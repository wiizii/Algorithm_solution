#include <iostream>
using namespace std;

int solution(int n) {
    int ans = 0;
    while (n != 0) {
        if (n & 1) {
            n -= 1;
            ans++;
        } else
            n /= 2;
    }
    return ans;
}