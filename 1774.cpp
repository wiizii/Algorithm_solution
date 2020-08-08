#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos {
	long long x, y;
};

struct Node {
	int from, to;
	double cost;
};

int parent[1001];
vector<Pos> v(1001);
vector<Node> adj;
int n, m;

int find(int u) {
	if (parent[u] == u)
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

double len(const Pos& a, const Pos& b) {
	return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

bool cmp(const Node& a, const Node& b) {
	return a.cost < b.cost;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v[i].x >> v[i].y;
		parent[i] = i;
	}
	for (int i = 1; i <= n - 1; i++) 
		for (int j = i + 1; j <= n; j++) 
			adj.push_back({ i,j,len(v[i],v[j]) });

	sort(adj.begin(), adj.end(), cmp);
	double ans = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}

	for (int i = 0; i < adj.size(); i++)
		if (merge(adj[i].from, adj[i].to))
			ans += adj[i].cost;

	printf("%.2lf\n", ans);
	return 0;
}
