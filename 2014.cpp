#include <iostream>
#include <set>
#include <queue>
#include <cstring>
#define ll long long
using namespace std;

priority_queue<ll, vector<ll>, greater<ll>> pq;
ll arr[101];
set<ll> s;
int k, n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	pq.push(1);
	ll maxValue = 0;

	while (n) {
		ll cur = pq.top();
		pq.pop();
		for (int i = 0; i < k; i++) {
			ll tmp = cur * arr[i];
			if (pq.size() > n && tmp > maxValue)
				continue;
			if (!s.count(tmp)) {
				maxValue = max(maxValue, tmp);
				pq.push(tmp);
				s.insert(tmp);
			}
		}
		n--;
	}

	cout << pq.top() << "\n";
}
