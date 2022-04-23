//atcoder educational dp contest problem z (frog 3)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int nmax = 2e5;
     
ll dp[nmax+5];
     
struct Line {
	ll a, b;
};
     
ll eval(ll X, Line D) {
	return X * D.a + D.b;
}
     
bool better(Line New, Line Old, Line Base) {
	return ((Base.b-New.b) * (Old.a-Base.a) <= (New.a-Base.a) * (Base.b-Old.b));
}
     
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	int n; ll c; cin >> n >> c;
	vector<Line> lower;
	int idx = 0;
	for(int i=1; i<=n; i++) {
		ll h; cin >> h;
		if(i == 1) 
			dp[i] = 0;
		else {
			while(idx<lower.size()-1 and eval(h, lower[idx]) >= eval(h, lower[idx+1])) idx++;
			dp[i] = eval(h, lower[idx]) + h * h + c;
		}
		Line temp;
		temp.a = (-2) * h;
		temp.b = dp[i] + h * h;
		while(lower.size()>=2 and better(temp, lower[lower.size()-1], lower[lower.size()-2])) lower.pop_back();
		lower.emplace_back(temp);
		idx = min(idx, int(lower.size()-1));
	}
	cout << dp[n];
	return 0;
}
