#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main() {
	int n,s;
	int start = 0, end = 1;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int sum = arr[start] + arr[end];
	int answer = 0x3f3f3f3f;
	while (start <= end && end < n) {
		if (s <= sum) 
			answer = min(answer, end - start + 1);
		if (start <= end && s <= sum) {
			sum -= arr[start];
			start++;
		}
		else if (end < n && s > sum) {
			end++;
			sum += arr[end];
		}
	}
	if (answer == 0x3f3f3f3f) 
		cout << 0 << "\n";
	else
		cout << answer << "\n";
}
