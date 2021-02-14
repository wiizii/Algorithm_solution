#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;

const int ans = 123456789;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
map<int,int> check;

int main() {
	int start = 0;
	for (int i = 0; i < 9; i++) {
		int x;
		cin >> x;
		if (x == 0)
			x = 9;
		start = start * 10 + x;
	}

	queue<int> q;
	q.push(start);
	check[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == ans)
			break;
		string s = to_string(cur);
		int k = s.find('9');
		int x = k / 3;
		int y = k % 3;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
				continue;
			string tmp = s;
			swap(tmp[x * 3 + y], tmp[nx * 3 + ny]);
			int n = stoi(tmp);
			if (!check.count(n)) {
				check[n] = check[cur] + 1;
				q.push(n);
			}
		}
	}

	if (!check.count(ans))
		cout << -1 << "\n";
	else
		cout << check[ans] << "\n";
}
