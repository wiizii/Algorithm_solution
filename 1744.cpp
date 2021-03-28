#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq_p, pq_n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > 0)
			pq_p.push(x);
		else
			pq_n.push(-x);
	}
	while (pq_p.size() >= 2) {
		int a = pq_p.top();
		pq_p.pop();
		int b = pq_p.top();
		pq_p.pop();
		if (a == 1 || b == 1)
			ans += a + b;
		else
			ans += a * b;
	}
	while (pq_n.size() >= 2) {
		int a = pq_n.top();
		pq_n.pop();
		int b = pq_n.top();
		pq_n.pop();
		ans += a * b;
	}
	if (!pq_p.empty())
		ans += pq_p.top();
	if (!pq_n.empty())
		ans += -pq_n.top();
	cout << ans << "\n";
}