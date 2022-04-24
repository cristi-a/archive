// https://cses.fi/problemset/list/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int nmax = 2500;
const ll inf = 1e15;

vector<vector<pair<int,int>>> dx(nmax+5);
ll dp[nmax+5];
int pre[nmax+5];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector<tuple<int,int,int>> v(m);
	for(auto &[x,y,cost] : v) cin >> x >> y >> cost;
	
	for(int i=1; i<=n; i++) dp[i] = inf;
	dp[1] = 0;
	
	int last;
	for(int i=1; i<=n; i++) {
		last = 0;
		for(auto [x,y,cost] : v) 
			if(dp[x] + cost < dp[y]) {
				dp[y] = dp[x] + cost;
				pre[y] = x;
				last = y;
			}
	}
	if(!last) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	vector<int> ans;
	for(int i=1; i<=n; i++) last = pre[last];
	for(int x=last; ; x = pre[x]) {
		ans.emplace_back(x);
		if(x == last and ans.size()>1) break;
	}
	reverse(ans.begin(), ans.end());
	for(auto x : ans) cout << x << " ";
	return 0;
}
