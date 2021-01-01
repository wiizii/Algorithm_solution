#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	int m ;
	string s;
	char ins;
	cin >> s >> m;

	list<char> str(s.begin(), s.end());
	auto cursor = str.end();

	for (int i = 0; i < m; i++) {
		cin >> ins;
		if (ins == 'L') {
			if (cursor != str.begin())
				cursor--;
		}
		else if (ins == 'D') {
			if (cursor != str.end())
				cursor++;
		}
		else if (ins == 'B') {
			if (cursor != str.begin())
				cursor = str.erase(--cursor);
		}
		else if (ins == 'P') {
			char ch;
			cin >> ch;
			str.insert(cursor, ch);
		}
	}
	for (auto &c : str)
		cout << c;
	return 0;
}