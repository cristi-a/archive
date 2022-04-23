/*
	updade - changes value of cell
 
	query - returns sum of given rectangle
*/

#include <bits/stdc++.h>
using namespace std;
const int nmax = 1000;

inline int lsb(int X) {
	return X & (-X);
}

int aib[nmax+5][nmax+5];

void update(int x, int y, int val) {
	for(int i=x; i<=nmax; i+=lsb(i))
		for(int j=y; j<=nmax; j+=lsb(i))
			aib[i][j] += val;
}

int query(int x1, int y1, int x2, int y2) {
	int rez = 0;
	for(int i=x2; i>=1; i-=lsb(i))
		for(int j=y2; j>=1; j-=lsb(j))
			rez += aib[i][j];
	for(int i=x1-1; i>=1; i-=lsb(i))
		for(int j=y2; j>=1; j-=lsb(j))
			rez -= aib[i][j];
	for(int i=x2; i>=1; i-=lsb(i))
		for(int j=y1-1; j>=1; j-=lsb(j))
			rez -= aib[i][j];
	for(int i=x1-1; i>=1; i-=lsb(i))
		for(int j=y1-1; j>=1; j-=lsb(j))
			rez += aib[i][j];
	return rez;
}
