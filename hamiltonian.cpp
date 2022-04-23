#include <bits/stdc++.h>
using namespace std;
const int nmax = 18;
const int inf = 0x3f3f3f3f;	

vector<vector<pair<int,int>>> dx(nmax);	
int dp[(1<<nmax)][nmax];	

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m; cin >> n >> m;
	for(int i=1; i<=m; i++) {
		int x,y,c; cin >> x >> y >> c;
		dx[y].emplace_back(x,c);
	}
	
	for(int i=0; i<(1<<n); i++)
		for(int j=0; j<n; j++)	
			dp[i][j] = inf;

	dp[1][0] = 0;
	for(int i=0; i<(1<<n); i++) 
		for(int j=0; j<n; j++) 
			if(i&(1<<j)) 
				for(auto x : dx[j]) 	
					dp[i][j] = min(dp[i][j], dp[i^(1<<j)][x.first] + x.second);

	int mn = inf;				
	for(auto i : dx[0])
		mn = min(mn, dp[(1<<n)-1][i.first] + i.second);
	if(mn!=inf) cout << mn;
	else cout << "IMPOSSIBLE";
	return 0;	
}
