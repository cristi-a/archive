#include <bits/stdc++.h>
using namespace std;
const int nmax = 2e5;
const int lgmax = 18;

int rmq[nmax+5][lgmax+5];
int v[nmax+5];
int Log2[nmax+5];

int main() {
	//construction
	for(int i=1; i<=nmax; i++) rmq[i][0] = v[i];
	for(int j=1; (1<<j)<=nmax; j++)
		for(int i=1; i+(1<<j)-1<=nmax; i++)
			rmq[i][j] = min(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
	for(int i=2; i<=nmax; i++) Log2[i] = Log2[i/2] + 1;

	//query
	int left, right; cin >> left >> right;
	int len = right - left + 1;
	cout << min(rmq[left][Log2[len]], rmq[right-(1<<Log2[len])+1][Log2[len]]);
	return 0;
}
