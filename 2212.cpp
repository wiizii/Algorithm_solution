#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	if (k >= n) {
		cout << 0 << "\n";
		return 0;
	}
	sort(v.begin(), v.end());
	vector<int> p(n - 1);
	for (int i = 0; i < n - 1; i++)
		p[i] = v[i + 1] - v[i];
	sort(p.begin(), p.end());
	int answer = 0;
	for (int i = 0; i < n - k; i++) {
		answer += p[i];
	}
	cout << answer << "\n";
}

