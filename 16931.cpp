#include <iostream>
using namespace std;

int main() {
	int n, m;
	int ans = 0;
	int arr[102][102] = { 0, };
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j])
				ans += 2;
		}
	}
	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int a, b, c, d;
			a = arr[i][j] - arr[i - 1][j];
			b = arr[i][j] - arr[i][j - 1];
			c = arr[i][j] - arr[i + 1][j];
			d = arr[i][j] - arr[i][j + 1];
			if(a > 0)
				ans += a;
			if(b > 0)
				ans += b;
			if(c > 0)
				ans += c;
			if(d > 0)
				ans += d;
		}
	}
	cout << ans << "\n";
	return 0;
}