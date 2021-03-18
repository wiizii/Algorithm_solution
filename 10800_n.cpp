#include <cstdio>

int n;
struct data {
    int color, size;
};
data arr[200010];
int max_size, sum_size, colors[200010], sizes[2010];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &arr[i].color, &arr[i].size);
        sum_size += arr[i].size;
        if (max_size < arr[i].size) max_size = arr[i].size;
        colors[arr[i].color] += arr[i].size;
        sizes[arr[i].size]++;
    }

    sizes[max_size] = max_size * sizes[max_size];
    for (int i = max_size - 1; i >= 1; i--) {
        sizes[i] = i * sizes[i] + sizes[i + 1];
        if (sizes[i] == sum_size) break;
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", sum_size - (colors[arr[i].color] * arr[i].size) -
                           (sizes[arr[i].size]) + arr[i].size);
    }
}