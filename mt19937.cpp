#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	const int key1 = 1e9 + 7;
	const int key2 = 1e9 + 9;
	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	cout << rng() % key1;
	return 0;
}
