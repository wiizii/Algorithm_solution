#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

int ans = 1;
int n;
vector<int> v;
int dp[2001][2001];

int solve(int i, int j) {
	if (i > j) return 0;
	else if (i == j) return 1;
	if (dp[i][j] != -1)
		return dp[i][j];
	dp[i][j] = 2;
	int d = v[j] - v[i];
	int k = v[j] + d;
	int idx = lower_bound(v.begin(), v.end(), k) - v.begin();
	if (idx < v.size() && v[idx] == k)
		return dp[i][j] = solve(j, idx) + 1;
	return dp[i][j];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	int tmp = 1;
	for (int i = 0; i < n-1; i++) {
		if (v[i] == v[i + 1]) {
			tmp++;
			ans = max(ans, tmp);
		}
		else
			tmp = 1;
	}
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size() - 1; i++)
		for (int j = i + 1; j < v.size(); j++)
			ans = max(ans, solve(i, j));
	cout << ans << "\n";
}
