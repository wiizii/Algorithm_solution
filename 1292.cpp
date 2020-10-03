#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= b; i++) {
		for (int j = 1; j <= i; j++) {
			v.push_back(i);
		}
	}
	int ans = 0;
	for (int i = a; i <= b; i++) {
		ans += v[i-1];
	}
	cout << ans << '\n';
}
