#include <bits/stdc++.h>
using namespace std;

int arr[102][102];
int tmp[102][102];
int n, m, r;

void a() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) tmp[n - i + 1][j] = arr[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) arr[i][j] = tmp[i][j];
}

void b() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) tmp[i][m - j + 1] = arr[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) arr[i][j] = tmp[i][j];
}

void c() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) tmp[j][n - i + 1] = arr[i][j];
    swap(n, m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) arr[i][j] = tmp[i][j];
}

void d() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) tmp[m - j + 1][i] = arr[i][j];
    swap(n, m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) arr[i][j] = tmp[i][j];
}

void e() {
    for (int i = 1; i <= n / 2; i++)
        for (int j = 1; j <= m / 2; j++) tmp[i][j + m / 2] = arr[i][j];
    for (int i = 1; i <= n / 2; i++)
        for (int j = m / 2 + 1; j <= m; j++) tmp[i + n / 2][j] = arr[i][j];
    for (int i = n / 2 + 1; i <= n; i++)
        for (int j = m / 2 + 1; j <= m; j++) tmp[i][j - m / 2] = arr[i][j];
    for (int i = n / 2 + 1; i <= n; i++)
        for (int j = 1; j <= m / 2; j++) tmp[i - n / 2][j] = arr[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) arr[i][j] = tmp[i][j];
}

void f() {
    for (int i = 1; i <= n / 2; i++)
        for (int j = 1; j <= m / 2; j++) tmp[i + n / 2][j] = arr[i][j];
    for (int i = n / 2 + 1; i <= n; i++)
        for (int j = 1; j <= m / 2; j++) tmp[i][j + m / 2] = arr[i][j];
    for (int i = n / 2 + 1; i <= n; i++)
        for (int j = m / 2 + 1; j <= m; j++) tmp[i - n / 2][j] = arr[i][j];
    for (int i = 1; i <= n / 2; i++)
        for (int j = m / 2 + 1; j <= m; j++) tmp[i][j - m / 2] = arr[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) arr[i][j] = tmp[i][j];
}

int main() {
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> arr[i][j];
    while (r--) {
        int t;
        cin >> t;
        if (t == 1)
            a();
        else if (t == 2)
            b();
        else if (t == 3)
            c();
        else if (t == 4)
            d();
        else if (t == 5)
            e();
        else if (t == 6)
            f();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}