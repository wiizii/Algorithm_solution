#include <algorithm>
#include <vector>
#include <iostream>
#define ll long long
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll ans = 0;
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n), d(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	vector<int> v1, v2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v1.push_back(a[i] + b[j]);
			v2.push_back(c[i] + d[j]);
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v1.size(); i++) {
		int l = lower_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
		int r = upper_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
		ans += r - l;
	}
	cout << ans << "\n";
}
