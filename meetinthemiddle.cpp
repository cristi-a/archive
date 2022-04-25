// https://cses.fi/problemset/task/1628
// do not use map if you don't want TLE
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int nmax = 40;
 
ll v[nmax+5], ans = 0, x;
vector<ll> lhs, rhs;
 
void Compute(int left, int right, vector<ll>&w) {
	int len = right - left + 1;
	for(int mask=0; mask<(1<<len); mask++) {
		ll s = 0;
		for(int b=0; b<20; b++)
			if(mask&(1<<b)) s += v[left+b];
		w.emplace_back(s);
	}
}
 
int main() {
 	ios::sync_with_stdio(0);
  	cin.tie(0);
  
  	int n; cin >> n >> x;
  	for(int i=1; i<=n; i++) cin >> v[i];
  	int mid = n / 2;
  	Compute(1, mid, lhs);
  	Compute(mid+1, n, rhs);
  	sort(rhs.begin(), rhs.end());
  	ll ct = 0;
  	for(auto i : lhs) ct += upper_bound(rhs.begin(), rhs.end(), x-i) - lower_bound(rhs.begin(), rhs.end(), x-i);
  	cout << ct;
  	return 0;
}
