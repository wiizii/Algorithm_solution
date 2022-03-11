#include <bits/stdc++.h>
using namespace std;
using tiii = tuple<int, int, int>;

const int MAX = 201;

int arr[MAX][MAX];
int n, k, s, x, y;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
priority_queue<tiii, vector<tiii>, greater<tiii>> pq[2];

void solve() {
	for (int i = 0; i < s; i++) {
		while (!pq[i % 2].empty()) {
			auto [t, x, y] = pq[i % 2].top();
			pq[i % 2].pop();
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny]) {
					continue;
				}
				arr[nx][ny] = t;
				pq[(i + 1) % 2].push({ t,nx,ny });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				pq[0].push({ arr[i][j], i,j });
			}
		}
	}
	cin >> s >> x >> y;
	solve();
	cout << arr[x-1][y-1] << "\n";
}
