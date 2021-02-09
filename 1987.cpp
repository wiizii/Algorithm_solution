#include <iostream>
#include <algorithm>
using namespace std;

int ans = 0;
int r, c;
char arr[21][21];
int check[26];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y, int cnt) {
	ans = max(ans, cnt);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			continue;
		int tmp = arr[nx][ny] - 65;
		if (!check[tmp]) {
			check[tmp] = true;
			dfs(nx, ny, cnt + 1);
			check[tmp] = false;
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) 
		for (int j = 0; j < c; j++) 
			cin >> arr[i][j];
	check[arr[0][0] - 65] = true;
	dfs(0, 0, 1);
	cout << ans << "\n";
}
