//using binary lifting
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int nmax = 2e5;
const int lgmax = 18;
 
vector<vector<int>> dx(nmax+5);
int up[nmax+5][lgmax+5], niv[nmax+5];
 
void dfs(int node, int father) {
	niv[node] = niv[father] + 1;
	up[node][0] = father;
	for(int i=1; i<=lgmax; i++)
		up[node][i] = up[up[node][i-1]][i-1];
	for(auto i : dx[node])
		if(i != father) 
			dfs(i, node);
}
 
int query(int a, int b) {
	if(niv[a] < niv[b]) swap(a, b);
	for(int i=lgmax; i>=0; i--)
		if(up[a][i] and niv[up[a][i]] >= niv[b])
			a = up[a][i];
	if(a == b) return a;
	for(int i=lgmax; i>=0; i--)
		if(up[a][i] and up[b][i] and up[a][i] != up[b][i]) {
			a = up[a][i];
			b = up[b][i];
		}
	return up[a][0];
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q; cin >> n >> q;
	for(int x=2; x<=n; x++) {
		int y; cin >>  y;
		dx[x].emplace_back(y);
		dx[y].emplace_back(x);
	}
	dfs(1, 0);
	for(int i=1; i<=q; i++) {
		int a, b; cin >> a >> b;
		cout << query(a, b) << "\n";
	}
	return 0;
}
