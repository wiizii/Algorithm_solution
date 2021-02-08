#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int swc[10001];
int order[10001];
int arr[10001];
int dp[10001];
int trace[10001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> swc[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		order[k] = i;
	}
	for (int i = 1; i <= n; i++)
		arr[i] = order[swc[i]];
		
	for (int i = 1; i <= n; i++) {
		int tmpMax = 0;
		int tmpJ = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (tmpMax <= dp[j]) {
					tmpMax = dp[j];
					tmpJ = j;
				}
			}
		}
		dp[i] = tmpMax + 1;
		trace[i] = tmpJ;
	}

	int ans_num = 0;
	int tmp = 0;
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (ans_num < dp[i]) {
			ans_num = dp[i];
			tmp = i;
		}
	}
	while (tmp != 0) {
		ans.push_back(swc[tmp]);
		tmp = trace[tmp];
	}
	sort(ans.begin(), ans.end());
	cout << ans_num << "\n";
	for (int& i : ans)
		cout << i << " ";
}
