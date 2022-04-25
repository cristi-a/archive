// Derangements in a sequence
// D(n) <=> Subfactorial of N
// D(n) = (D(n-1) + D(n-2)) * (n-1)
// https://cses.fi/problemset/task/1717

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int nmax = 1e6;
const ll modulo = 1e9 + 7;

int dp[nmax+5];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;	
	dp[2] = 1;
	for(int i=3; i<=n; i++)
		dp[i] = 1LL * ((1LL * dp[i-1] + 1LL * dp[i-2]) % modulo) * (1LL * i - 1LL) % modulo;
	cout << dp[n];
	return 0;
}
