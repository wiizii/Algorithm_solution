#include <cmath>
#include <iostream>
using namespace std;

double arr[2501];

int main() {
    int n, k;
    cin >> n >> k;
    double a = 0;
    for (int i = 1; i <= n; i++) {
        double x;
        cin >> x;
        a += x * i;
    }
    cout << a;
}