#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 200002;

int A[MAX];

void manachers(string s) {
	int r = 0, p = 0;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (i <= r)
			A[i] = min(A[2 * p - i], r - i);
		else
			A[i] = 0;
		while (i - A[i] - 1 >= 0 && i + A[i] + 1 < n && s[i - A[i] - 1] == s[i + A[i] + 1])
			A[i]++;
		if (r < i + A[i]) {
			r = i + A[i];
			p = i;
		}
	}
}

int main() {
	string s, tmp = "#";
	int answer = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		tmp += s[i];
		tmp += "#";
	}
	manachers(tmp);
	for (int i = 0; i < tmp.size(); i++) 
		answer = max(answer, A[i]);
	cout << answer << "\n";
}