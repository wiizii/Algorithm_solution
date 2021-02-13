#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct Trace {
	int pos, val;
};

int n;
int arr[1000001];
int lis[1000001];
Trace trace[1000001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	lis[0] = arr[0];
	trace[0].pos = 0;
	trace[0].val = arr[0];

	int p = 0;
	for (int i = 1; i < n; i++) {
		if (lis[p] < arr[i]) {
			lis[++p] = arr[i];
			trace[i].pos = p;
			trace[i].val = arr[i];
		}
		else {
			int idx = lower_bound(lis, lis + p, arr[i]) - lis;
			lis[idx] = arr[i];
			trace[i].pos = idx;
			trace[i].val = arr[i];
		}
	}
	cout << p + 1 << "\n";
	stack<int> s;
	int cur = p;
	for (int k = n - 1; k >= 0; k--) {
		if (cur == trace[k].pos) {
			s.push(trace[k].val);
			cur--;
		}
	}
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}