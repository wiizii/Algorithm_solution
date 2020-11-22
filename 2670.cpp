#include <cstdio>

double arr[10001];
int n;

double max(double a, double b) { return a > b ? a : b; }

int main() {
    double ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lf", &arr[i]);

    for (int i = 0; i < n; i++) {
        double tmp = 1;
        for (int j = i; j < n; j++) {
            tmp *= arr[j];
            ans = max(ans, tmp);
        }
    }

    printf("%0.3lf\n", ans);

    return 0;
}