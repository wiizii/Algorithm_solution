#include <iostream>
#define ll long long
#define mod 1000000007
using namespace std;

struct matrix {
	ll f[2][2];
};

matrix operator*(matrix& a, matrix& b) {
	matrix ret = { 0,0,0,0 };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ret.f[i][j] += a.f[i][k] * b.f[k][j];
			}
			ret.f[i][j] %= mod;
		}
	}
	return ret;
}

int main() {
	ll n;
	cin >> n;
	matrix a = { 1,1,1,0 };
	matrix b = { 1,0,0,1 };
	while (n != 0) {
		if (n & 1)
			b = b * a;
		a = a * a;
		n /= 2;
	}
	cout << b.f[0][1] << "\n";
	return 0;
}