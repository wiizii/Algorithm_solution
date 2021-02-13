#include <bitset>
#include <cstdio>
using namespace std;

bitset<33554432> bs;

int main() {
	int n;
	while (~scanf("%d", &n)) {
		if (!bs[n])
			printf("%d ", n);
		bs[n] = 1;
	}
}
