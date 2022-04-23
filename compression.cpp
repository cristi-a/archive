#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5;

int v[nmax+5];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	vector<int> vals;
	for(int i=1; i<=n; i++) {
		cin >> v[i];
		vals.emplace_back(v[i]);
	}
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	for(int i=1; i<=n; i++) v[i] = lower_bound(vals.begin(), vals.end(), v[i]) - vals.begin() + 1;
	return 0;
}
