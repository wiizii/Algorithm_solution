#include <cstdio>
#define ll long long

int main() {
    ll n;
    scanf("%lld", &n);
    n & 1 ? printf("SK\n") : printf("CY");
}