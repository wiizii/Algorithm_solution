#include <cstring>
#include <iostream>
using namespace std;

int main() {
    bool broken[10];
    memset(broken, true, sizeof(broken));
    int to, from = 100, m;
    cin >> to >> m;
    while (m--) {
        int k;
        scanf("%d", &k);
        broken[k] = false;
    }

    return 0;
}