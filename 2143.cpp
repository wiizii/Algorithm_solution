#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll t;
ll ans = 0;
int n, m;
ll A[1001], B[1001];
vector<ll> a, b;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> B[i];
	for (int i = 0; i < n; i++) {
		ll tmp = A[i];
		a.push_back(tmp);
		for (int j = i + 1; j < n; j++) {
			tmp += A[j];
			a.push_back(tmp);
		}
	}
	for (int i = 0; i < m; i++) {
		ll tmp = B[i];
		b.push_back(tmp);
		for (int j = i + 1; j < m; j++) {
			tmp += B[j];
			b.push_back(tmp);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < a.size(); i++) {
		int l = lower_bound(b.begin(), b.end(), t - a[i]) - b.begin();
		int r = upper_bound(b.begin(), b.end(), t - a[i]) - b.begin();
		ans += r - l;
	}
	cout << ans << "\n";
}
