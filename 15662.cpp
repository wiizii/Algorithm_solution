#include <cstdio>
#include <deque>
using namespace std;

int t;
deque<int> gear[1001];
void cw(int n, int d);
void ccw(int n, int d);

void cw(int n, int d) {
    if (n != 0 && (d == -1 || d == 0) && gear[n][6] != gear[n - 1][2])
        ccw(n - 1, -1);
    if (n != t - 1 && (d == 1 || d == 0) && gear[n][2] != gear[n + 1][6])
        ccw(n + 1, 1);
    gear[n].push_front(gear[n].back());
    gear[n].pop_back();
}

void ccw(int n, int d) {
    if (n != 0 && (d == -1 || d == 0) && gear[n][6] != gear[n - 1][2])
        cw(n - 1, -1);
    if (n != t - 1 && (d == 1 || d == 0) && gear[n][2] != gear[n + 1][6])
        cw(n + 1, 1);
    gear[n].push_back(gear[n].front());
    gear[n].pop_front();
}

int main() {
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 8; j++) {
            int n;
            scanf("%1d", &n);
            gear[i].push_back(n);
        }
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int n, d;
        scanf("%d %d", &n, &d);
        n--;
        if (d == 1)
            cw(n, 0);
        else
            ccw(n, 0);
    }
    int ans = 0;
    for (int i = 0; i < t; i++)
        if (gear[i][0]) ans++;
    printf("%d\n", ans);
}