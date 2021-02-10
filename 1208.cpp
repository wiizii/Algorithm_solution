#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[41];
int n, s;

bool cmp(const int& a, const int& b) {
	return a > b;
}

long long solve() {
	int half = n / 2;
	int fsize = (1 << (n - half)), bsize = (1 << half);
	vector<int> front(fsize), back(bsize);
	for (int i = 0; i < fsize; i++)
		for (int j = 0; j < n - half; j++)
			if (i & (1 << j)) front[i] += arr[j];
	for (int i = 0; i < bsize; i++)
		for (int j = 0; j < half; j++)
			if (i & (1 << j)) back[i] += arr[j + (n - half)];
	sort(front.begin(), front.end());
	sort(back.begin(), back.end(), cmp);
	int fidx = 0, bidx = 0;
	long long ret = 0;
	while (fidx < fsize && bidx < bsize) {
		int p = front[fidx] + back[bidx];
		if (p == s) {
			long long fcnt = 1, bcnt = 1;
			fidx++, bidx++;
			while (fidx < fsize && front[fidx] == front[fidx - 1]) {
				fidx++;
				fcnt++;
			}
			while (bidx < bsize && back[bidx] == back[bidx - 1]) {
				bidx++;
				bcnt++;
			}
			ret += fcnt * bcnt;
		}
		else if (p < s)
			fidx++;
		else if (p > s)
			bidx++;
	}
	return  s == 0 ? ret - 1 : ret;

}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << solve() << "\n";
}
