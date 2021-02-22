#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool prime[1000001];

int main() {
	int t;
	cin >> t;
	for (int i = 2; i <= 1000000; i++) 
		prime[i] = true;
	for (int i = 2; i * i <= 1000000; i++) 
		if (prime[i])
			for (int j = i * i; j <= 1000000; j += i)
				prime[j] = false;

	while (t--) {
		int n;
		cin >> n;
		int cnt = 0;
		for (int i = 2; i+i <= n; i++) 
			if (prime[i] && prime[n - i])
				cnt++;
		cout << cnt << "\n";
	}
}