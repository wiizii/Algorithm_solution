#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> m1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string domain, password;
		cin >> domain >> password;
		m1.insert({ domain, password });
	}
	while (m--) {
		string domain;
		cin >> domain;
		cout << m1[domain] << '\n';
	}
	return 0;
}
