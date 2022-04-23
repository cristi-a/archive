//arbore partial de cost minim
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int nmax = 1e5;
 
int comp[nmax+5], dim[nmax+5];
 
int Find(int node) {
	if(comp[node] == node) return node;
	comp[node] = Find(comp[node]);
	return comp[node];
}
 
void Union(int a, int b) {
	int ra = Find(a), rb = Find(b);
	if(dim[ra] > dim[rb]) swap(ra, rb);
	comp[ra] = comp[rb];
	dim[rb] += dim[ra];
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i=1; i<=n; i++) comp[i] = i, dim[i] = 1;
	vector<tuple<ll, int, int>> v;
	for(int i=1; i<=m; i++) {
		int x, y, cost; cin >> x >> y >> cost;
		v.emplace_back(cost, x, y);
	}
	sort(v.begin(), v.end());
	ll sum = 0;
	for(auto [cost, x, y] : v) {
		if(Find(x) != Find(y)) {
			Union(x, y);
			sum += cost;
		}
	}
	cout << sum;
	return 0;
}
