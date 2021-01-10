#include <iostream>
using namespace std;

int main() {
	int n;
	long long sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i < 10)
			sum += 1;
		else if (10 <= i && i < 100)
			sum += 2;
		else if (100 <= i && i < 1000)
			sum += 3;
		else if (1000 <= i && i < 10000)
			sum += 4;
		else if (10000 <= i&& i < 100000)
			sum += 5;
		else if (100000 <= i && i < 1000000)
			sum += 6;
		else if (1000000 <= i && i < 10000000)
			sum += 7;
		else if (10000000 <= i && i < 100000000)
			sum += 8;
		else
			sum += 9;
	}
	cout << sum << "\n";
	return 0;
}