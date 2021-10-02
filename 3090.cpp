#include <iostream>
using namespace std;

const int MAX = 100001;
int n, t;
int arr[MAX];
int tmp[MAX];
int answer[MAX];

bool isPossible(int mid) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		tmp[i] = arr[i];
	for (int i = 0; i < n - 1; i++) {
		if (tmp[i + 1] - tmp[i] > mid) {
			cnt += tmp[i + 1] - (tmp[i] + mid);
			tmp[i + 1] = tmp[i] + mid;
		}
	}
	for (int i = n-1; i > 0; i--) {
		if (tmp[i - 1] - tmp[i] > mid) {
			cnt += tmp[i - 1] - (tmp[i] + mid);
			tmp[i - 1] = tmp[i] + mid;
		}
	}
	if (cnt <= t) {
		for (int i = 0; i < n; i++) {
			answer[i] = tmp[i];
		}
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> t;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];

	int l = 0, r = 1000000000;

	while (l <= r) {
		int mid = (l + r) / 2;
		if (isPossible(mid))
			r = mid - 1;
		else
			l = mid + 1;

	}
	for (int i = 0; i < n; i++) 
		cout << answer[i] << " ";
}
