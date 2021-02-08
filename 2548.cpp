#include <iostream>
#include <algorithm>
using namespace std;

int arr[20001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int mid = n & 1 ? n / 2 : n / 2 - 1;
	cout << arr[mid] << "\n";
}
