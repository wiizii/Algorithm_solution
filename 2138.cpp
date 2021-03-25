#include <cstdio>

const int MAX = 100001;
int a[MAX];
int b[MAX];
int c[MAX];
int n;

int main() {
    scanf("%d", &n);
    int ans_a = 0;
    int ans_b = 1;
    for (int i = 0; i < n; i++) {
        scanf("%1d", &a[i]);
        b[i] = a[i];
    }
    for (int i = 0; i < n; i++) scanf("%1d", &c[i]);
    b[0] = !b[0];
    b[1] = !b[1];
    for (int i = 1; i < n; i++) {
        if (a[i - 1] ^ c[i - 1]) {
            ans_a++;
            a[i - 1] = !a[i - 1];
            a[i] = !a[i];
            a[i + 1] = !a[i + 1];
        }
        if (b[i - 1] ^ c[i - 1]) {
            ans_b++;
            b[i - 1] = !b[i - 1];
            b[i] = !b[i];
            b[i + 1] = !b[i + 1];
        }
    }
    bool flag1 = true;
    bool flag2 = true;
    for (int i = 0; i < n; i++) {
        if (a[i] ^ c[i]) flag1 = false;
        if (b[i] ^ c[i]) flag2 = false;
        if (!flag1 && !flag2) break;
    }
    if (flag1 && flag2) {
        if (ans_a < ans_b)
            printf("%d\n", ans_a);
        else
            printf("%d\n", ans_b);
    }
    if (flag1 && !flag2) printf("%d\n", ans_a);
    if (!flag1 && flag2) printf("%d\n", ans_b);
    if (!flag1 && !flag2) printf("-1\n");
}