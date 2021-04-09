#include <algorithm>
#include <iostream>
using namespace std;

int N;
int arr[100001] = {0, 3, 7};

int solve(int n) {
    if (arr[n]) return arr[n];
    int &ret = arr[n];
    ret = solve(n - 1) * 2 + solve(n - 2);
    ret %= 9901;
    return ret;
}

int main() {
    cin >> N;
    cout << solve(N) << "\n";
}