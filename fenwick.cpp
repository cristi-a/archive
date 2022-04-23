#include <bits/stdc++.h>
using namespace std;
const int nmax = 2e5;

inline int lsb(int X) {
	return X & (-X);
}

int fenwick[nmax+5];

void update(int pos) {
	for(int i=pos; i<=nmax; i+=lsb(i))
		//update
}

int query(int pos) {
	int rez = 0;
	for(int i=pos; i>=1; i-=lsb(i))
		//query
	return rez;
}
