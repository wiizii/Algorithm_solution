#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
int arr[31];

int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int half = n / 2;
	int fsize = (1 << (n - half)), bsize = (1 << half);
	vector<long long> front(fsize), back(bsize);
	for (int i = 0; i < fsize; i++)
		for (int j = 0; j < n - half; j++)
			if (i & (1 << j)) front[i] += arr[j];
	for (int i = 0; i < bsize; i++)
		for (int j = 0; j < half; j++)
			if (i & (1 << j)) back[i] += arr[j + (n - half)];
	sort(front.begin(), front.end());
	long long ans = 0;
	for (int i = 0; i < back.size(); i++) {
		long long& cur = back[i];
		if(c >= cur)
			ans += upper_bound(front.begin(), front.end(), c - cur) - front.begin();
	}
	cout << ans << "\n";

}
}