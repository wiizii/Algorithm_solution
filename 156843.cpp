#include <iostream>
#include <algorithm>
using namespace std;

int N, M, H;
int ans = 4;
int ladder[32][12];

bool checkAns() {
	for (int i = 1; i <= N; i++) {
		int end = i;
		for (int j = 1; j <= H; j++) {
			if (ladder[j][end])
				end++;
			else if (ladder[j][end - 1])
				end--;
		}
		if (end != i)
			return false;
	}

	return true;
}

void solve(int cnt,int istart, int jstart) {
	if (checkAns()) {
		if (ans > cnt) {
			ans = cnt;
			return;
		}
	}
	if (cnt == 3)
		return;
	
	for (int i = istart; i <= H; i++) {
		for (int j = (i == istart ? jstart : 1); j < N; j++) {
			if (!ladder[i][j]) {
				if (ladder[i][j - 1] || ladder[i][j + 1])
					continue;
				else {
					ladder[i][j] = 1;
					if(cnt < ans)
						solve(cnt + 1,i,j);
					ladder[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a][b] = 1;
	}
	solve(0,1,1);
	if (ans == 4)
		cout << -1 << "\n";
	else
		cout << ans << "\n";
	return 0;
}
