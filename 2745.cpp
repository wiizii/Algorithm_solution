#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	int ans = 0;
	string s;
	int b;
	cin >> s >> b;
	reverse(s.begin(), s.end());
	for (int i = 0, k=1; i < s.size(); i++, k *= b) {
		if (isdigit(s[i])) 
			ans += (s[i] - '0') * k;
		if (isupper(s[i]))
			ans += (s[i] - 'A' + 10) * k;
	}
	cout << ans << "\n";
	return 0;
}