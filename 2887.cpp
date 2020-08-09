#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int n, x, y, z;
};
struct Edge {
	int cost, from, to;
};

bool cmpx(const Node& a, const Node& b) {
	return a.x < b.x;
}

bool cmpy(const Node& a, const Node& b) {
	return a.y < b.y;
}

bool cmpz(const Node& a, const Node& b) {
	return a.z < b.z;
}

bool cmp(const Edge& a, const Edge& b) {
	return a.cost < b.cost;
}

int abs(int a) {
	return a >= 0 ? a : -a;
}

int parent[100001];

int find(int u) {
	if (u == parent[u])
		return u;
	return parent[u] = find(parent[u]);
}

bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)
		return false;
	parent[u] = v;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<Node> p;
	vector<Edge> e;
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		p.push_back({ i,x,y,z });
		parent[i] = i;
	}
	sort(p.begin(), p.end(), cmpx);
	for (int i = 0; i < n - 1; i++) {
		e.push_back({ abs(p[i].x - p[i + 1].x),p[i].n,p[i + 1].n });
	}
	sort(p.begin(), p.end(), cmpy);
	for (int i = 0; i < n - 1; i++) {
		e.push_back({ abs(p[i].y - p[i + 1].y),p[i].n,p[i + 1].n });
	}
	sort(p.begin(), p.end(), cmpz);
	for (int i = 0; i < n - 1; i++) {
		e.push_back({ abs(p[i].z - p[i + 1].z),p[i].n,p[i + 1].n });
	}

	sort(e.begin(), e.end(), cmp);
	for (int i = 0; i < e.size(); i++) {
		if (merge(e[i].from, e[i].to))
			ans += e[i].cost;
	}
	cout << ans << "\n";
	return 0;
}
