#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;
int n, m, k;
int arr[MAX];
bool check[MAX];
int ans = -0x3f3f3f3f;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };

bool isPossible(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
			continue;
		}
		int num = nr * m + nc;
		if (check[num])
			return false;
	}
	return true;
}

void solve(int cnt, int idx) {
	if (cnt == k) {
		int acc = 0;
		for (int i = 0; i < n * m; i++) {
			if (check[i]) {
				acc += arr[i];
			}
		}
		ans = max(ans, acc);
		return;
	}
	for (int i = idx; i < n * m; i++) {
		int r = i / m;
		int c = i % m;
		if (isPossible(r,c)) {
			check[i] = true;
			solve(cnt + 1, i + 1);
			check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n * m; i++) {
		cin >> arr[i];
	}
	solve(0, 0);
	cout << ans << "\n";
}
