/*
	Modular inverse with extended Euclidian algorithm
	
	for inverse of A (mod M)
	euclid(A, M, d, invA, y)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;	
 
void euclid(ll a, ll b, ll &d, ll &x, ll &y) {
	if(b==0) {
		d = a;
		x = 1;
		y = 0;
	}
	else {
		ll x1, y1;
		euclid(b, a%b, d, x1, y1);
		x = y1;
		y = x1 - 1LL * (a / b) * y1;
	}	
}	
