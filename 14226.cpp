#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int check[1001][1001];

int main() {
	int s;
	queue<pair<int, int>> q;
	cin >> s;
	q.push({ 1,0 });
	memset(check, -1, sizeof(check));
	check[1][0] = 0;

	while (!q.empty()) {
		int dist = q.front().first;
		int clip = q.front().second;
		q.pop();
		if (dist == s) {
			cout << check[dist][clip] << "\n";
			break;
		}
		if (check[dist][dist] == -1) {
			q.push({ dist,dist });
			check[dist][dist] = check[dist][clip] + 1;
		}
		if (dist + clip < 1001 && check[dist + clip][clip] == -1) {
			q.push({ dist + clip, clip });
			check[dist + clip][clip] = check[dist][clip] + 1;
		}
		if (dist > 0 && check[dist - 1][clip] == -1) {
			q.push({ dist - 1 , clip });
			check[dist - 1][clip] = check[dist][clip] + 1;
		}
	}

	return 0;
}
