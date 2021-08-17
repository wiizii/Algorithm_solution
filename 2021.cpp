#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 200010;
int n, l;
int start, last;
vector<int> adj[MAX];
bool check[MAX];

int bfs() {
	int ret = 0;
	queue<int> q;
	q.push(start);
	check[start] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == last) 
			return ret-1;
		for (auto next : adj[cur]) {
			if (!check[next]) {
				if (next > n)
					ret++;
				check[next] = true;
				q.push(next);
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l;
	for (int i = n+1; i <= n+l; i++) {
		while (1) {
			int x;
			cin >> x;
			if (x == -1)
				break;
			adj[i].push_back(x);
			adj[x].push_back(i);
		}
	}
	cin >> start >> last;
	if (start == last) {
		cout << 0 << "\n";
		return 0;
	}
	cout << bfs() << "\n";

}