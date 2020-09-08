#include <cstdio>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if (n & 1)
        printf("CY\n");
    else
        printf("SK\n");
    return 0;
}