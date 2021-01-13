#include <iostream>
#define MAX 100000
#define ll long long
using namespace std;

int n;
int cost[MAX];
int dist[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll answer = 0;
	ll min_cost = 0x3f3f3f3f3f3f3f3f;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
		cin >> dist[i];
	for (int i = 0; i < n; i++)
		cin >> cost[i];

	min_cost = cost[0];
	for (int i = 0; i < n - 1; i++) {
		if (min_cost > cost[i])
			min_cost = cost[i];
		answer += min_cost * dist[i];
	}
	cout << answer << "\n";
	return 0;
}