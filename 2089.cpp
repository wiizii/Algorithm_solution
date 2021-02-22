#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << "0\n";
		return 0;
	}
	string ans = "";
	while (n != 0) {
		if (n % -2 == 0) {
			ans += "0";
			n /= -2;
		}
		else {
			ans += "1";
			n = (n - 1) / -2;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
}