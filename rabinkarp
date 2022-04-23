// string matching using hashes
#include <bits/stdc++.h>
using namespace std;
const int B = 31;
const int key = 1e9 + 7;
const int nmax = 1e6;

int h[nmax+5], p[nmax+5];

void init(int len) {
	p[0] = 1;
	for(int i=1; i<=len; i++) 
		p[i] = 1LL * p[i-1] * B % key;
}

int get(int l, int r) {
	int val = (h[r] - (1LL * h[l] * p[r-l]) % key) % key;
	if(val < 0) val = val + key;
	return val;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string a, b; cin >> a >> b;
	init(a.size());
	int n = a.size(), m = b.size();
	
	int ref = 0;
	for(int i=0; i<m; i++) ref = (1LL * ref * B % key + (b[i] - 'a' + 1)) % key;
	for(int i=0; i<n; i++) h[i+1] = (1LL * h[i] * B % key + 1LL * (a[i] - 'a' + 1)) % key;
	
	int nr = 0;
	for(int i=1; i<=n; i++) 
		if(i >= m and get(i-m, i) == ref) nr++; 
	
	cout << nr;
	return 0;
}
